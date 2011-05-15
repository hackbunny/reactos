/*
 * File System Bind Data object to use as parameter for the bind context to
 * IShellFolder_ParseDisplayName
 *
 * Copyright 2003 Rolf Kalbermatter
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 *
 */

#include <precomp.h>
#include <tchar.h>
#include <atlbase.h>
#include <atlcom.h>
#include <atlwin.h>

WINE_DEFAULT_DEBUG_CHANNEL(pidl);

/***********************************************************************
 * IFileSystemBindData implementation
 */
class IFileSystemBindDataImpl :
	public CComObjectRootEx<CComMultiThreadModelNoCS>,
	public IFileSystemBindData
{
private:
    WIN32_FIND_DATAW findFile;
public:
	IFileSystemBindDataImpl();
	~IFileSystemBindDataImpl();

    // *** IFileSystemBindData methods ***
    virtual HRESULT STDMETHODCALLTYPE SetFindData(const WIN32_FIND_DATAW *pfd);
    virtual HRESULT STDMETHODCALLTYPE GetFindData(WIN32_FIND_DATAW *pfd);

DECLARE_NOT_AGGREGATABLE(IFileSystemBindDataImpl)
DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(IFileSystemBindDataImpl)
	COM_INTERFACE_ENTRY_IID(IID_IFileSystemBindData, IFileSystemBindData)
END_COM_MAP()
};

static const WCHAR wFileSystemBindData[] = {
    'F','i','l','e',' ','S','y','s','t','e','m',' ','B','i','n','d','D','a','t','a',0};

HRESULT WINAPI IFileSystemBindData_Constructor(const WIN32_FIND_DATAW *pfd, LPBC *ppV)
{
	CComPtr<IFileSystemBindData>		fileSystemBindData;
	CComPtr<IBindCtx>					bindContext;
	BIND_OPTS							bindOpts;
	HRESULT								hResult;

    TRACE("%p, %p\n", pfd, ppV);

    if (ppV == NULL)
       return E_INVALIDARG;

    *ppV = NULL;

	hResult = IFileSystemBindDataImpl::_CreatorClass::CreateInstance(NULL, IID_IFileSystemBindData, (void **)&fileSystemBindData);
	if (FAILED(hResult))
		return hResult;
    hResult = fileSystemBindData->SetFindData(pfd);
	if (FAILED(hResult))
		return hResult;

	hResult = CreateBindCtx(0, &bindContext);
	if (FAILED(hResult))
		return hResult;
    bindOpts.cbStruct = sizeof(BIND_OPTS);
    bindOpts.grfFlags = 0;
    bindOpts.grfMode = STGM_CREATE;
    bindOpts.dwTickCountDeadline = 0;
    hResult = bindContext->SetBindOptions(&bindOpts);
	if (FAILED(hResult))
		return hResult;
    hResult = bindContext->RegisterObjectParam((LPOLESTR)wFileSystemBindData, fileSystemBindData);
	if (FAILED(hResult))
		return hResult;

	*ppV = bindContext.Detach();

    return S_OK;
}

HRESULT WINAPI FileSystemBindData_GetFindData(LPBC pbc, WIN32_FIND_DATAW *pfd)
{
	CComPtr<IUnknown>					pUnk;
	CComPtr<IFileSystemBindData>		pfsbd;
	HRESULT								ret;

    TRACE("%p, %p\n", pbc, pfd);

    if (!pfd)
        return E_INVALIDARG;

    ret = pbc->GetObjectParam((LPOLESTR)wFileSystemBindData, &pUnk);
    if (SUCCEEDED(ret))
    {
        ret = pUnk->QueryInterface(IID_IFileSystemBindData, (LPVOID *)&pfsbd);
        if (SUCCEEDED(ret))
            ret = pfsbd->GetFindData(pfd);
    }
    return ret;
}

HRESULT WINAPI FileSystemBindData_SetFindData(LPBC pbc, const WIN32_FIND_DATAW *pfd)
{
	CComPtr<IUnknown>					pUnk;
	CComPtr<IFileSystemBindData>		pfsbd;
	HRESULT								ret;

    TRACE("%p, %p\n", pbc, pfd);

    ret = pbc->GetObjectParam((LPOLESTR)wFileSystemBindData, &pUnk);
    if (SUCCEEDED(ret))
    {
        ret = pUnk->QueryInterface(IID_IFileSystemBindData, (LPVOID *)&pfsbd);
        if (SUCCEEDED(ret))
            ret = pfsbd->SetFindData(pfd);
    }
    return ret;
}

IFileSystemBindDataImpl::IFileSystemBindDataImpl()
{
	memset(&findFile, 0, sizeof(WIN32_FIND_DATAW));
}

IFileSystemBindDataImpl::~IFileSystemBindDataImpl()
{
	TRACE(" destroying ISFBindPidl(%p)\n", this);
}

HRESULT WINAPI IFileSystemBindDataImpl::GetFindData(WIN32_FIND_DATAW *pfd)
{
    TRACE("(%p), %p\n", this, pfd);

    if (!pfd)
        return E_INVALIDARG;

    memcpy(pfd, &findFile, sizeof(WIN32_FIND_DATAW));
    return NOERROR;
}

HRESULT WINAPI IFileSystemBindDataImpl::SetFindData(const WIN32_FIND_DATAW *pfd)
{
    TRACE("(%p), %p\n", this, pfd);

    if (pfd)
        memcpy(&findFile, pfd, sizeof(WIN32_FIND_DATAW));
    else
        memset(&findFile, 0, sizeof(WIN32_FIND_DATAW));
    return NOERROR;
}
