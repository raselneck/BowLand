#pragma once

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX

#include <Windows.h>
#include <d3d11.h>
#include <DirectXMath.h>
#include "dxerr.h"
#include <string>

/// <summary>
/// Safely releases the given COM pointer.
/// </summary>
/// <param name="x">The COM pointer.</param>
#define ReleaseMacro(x) if ( x ) { x->Release(); x = nullptr; }

/// <summary>
/// Safely adds a reference the given COM pointer.
/// </summary>
/// <param name="x">The COM pointer.</param>
#define AddRefMacro(x) if ( x ) x->AddRef()

/// <summary>
/// Updates a D3D resource by releasing it, assigning it a new value, and adding a reference to it.
/// </summary>
/// <param name="resource">The resource to update.</param>
/// <param name="value">The new value.</param>
#define UpdateD3DResource(resource, value) \
    ReleaseMacro( resource ); \
    resource = value; \
    AddRefMacro( resource )

/// <summary>
/// Updates a shared pointer with the given value.
/// </summary>
/// <param name="ptr">The shared pointer.</param>
/// <param name="value">The new shared pointer value.</param>
#define UpdateSharedPtr(ptr, value) if ( ptr.get() != value.get() ) ptr = value

// --------------------------------------------------------
// Macro for checking the result of a DirectX function call.  This will
// pop up a message box on a failed result and then quit.  This macro
// depends on the "dxerr" (DirectX Error) helper files.
//
// In release mode this macro effectively does nothing.
// --------------------------------------------------------
#if defined(DEBUG) | defined(_DEBUG)
    #ifndef HR
    #define HR(x)												\
    {															\
        HRESULT hr = (x);										\
        if(FAILED(hr))											\
        {														\
            DXTrace(__FILEW__, (DWORD)__LINE__, hr, L#x, true);	\
            PostQuitMessage(0);									\
        }														\
    }														
    #endif
#else
    #ifndef HR
    #define HR(x) (x) // Do nothing special!
    #endif
#endif
