/*

 Copyright (c) 2007-2010 Olivier Chafik <olivier.chafik@gmail.com>

 Permission to use, copy, modify, and distribute this software for any
 purpose with or without fee is hereby granted, provided that the above
 copyright notice and this permission notice appear in all copies.

 THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.

*/

/*

  dynload_darwin.c

  dynload module for .dylib (mach-o darwin/OS X) files

*/


#include "dynload.h"

#include <dlfcn.h>

struct DLLib_
{
	char* libPath;
	void* handle;
};


DLLib* dlLoadLibrary(const char* libPath)
{
	void* handle;
	size_t len;
	DLLib* lib;
	
	handle = dlopen(libPath, RTLD_LAZY);
	if (!handle)
		return NULL;
	
	len = strlen(libPath);
	lib = (DLLib*)dcAllocMem(sizeof(DLLib));
	lib->libPath = (char*)dcAllocMem(len + 1);
	strcpy(lib->libPath, libPath);
	lib->libPath[len] = '\0';
	lib->handle = handle;
	return lib;
}


void* dlFindSymbol(DLLib* libHandle, const char* symbol)
{
  return dlsym(libHandle && libHandle->handle ? libHandle->handle : RTLD_DEFAULT, symbol);
}


void  dlFreeLibrary(DLLib* libHandle)
{
	if (!libHandle)
		return;
	
	dlclose(libHandle->handle);
	dcFreeMem(libHandle->libPath);
	dcFreeMem(libHandle);
}

