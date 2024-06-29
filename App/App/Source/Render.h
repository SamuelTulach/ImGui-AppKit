#pragma once

namespace Render
{
    namespace Data
    {
        inline HWND MainWindow;
        inline ID3D11Device* Device;
        inline ID3D11DeviceContext* DeviceContext;
        inline IDXGISwapChain* SwapChain;
        inline ID3D11RenderTargetView* RenderTargetView;
    }

    bool CreateRenderTarget();
    bool CreateDevice();

    void CleanupRenderTarget();
    void CleanupDevice();

    void Loop();

    LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
}