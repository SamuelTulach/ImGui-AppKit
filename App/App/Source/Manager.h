#pragma once

namespace Manager
{
    namespace Data
    {
        inline WindowBase* CurrentWindow = nullptr;
        inline float NextSizeX = 300.0f;
        inline float NextSizeY = 300.0f;
    }

    void InitDefault();
    void SetNextSize(float width, float height);
    void ClearWindow();
    void SwitchWindow(WindowBase* newWindow);
    void Render();
}
