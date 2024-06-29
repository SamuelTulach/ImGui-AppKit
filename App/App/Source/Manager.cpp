#include "Global.h"

void Manager::InitDefault()
{
    Data::CurrentWindow = new LoginWindow();
}

void Manager::SetNextSize(const float width, const float height)
{
    Data::NextSizeX = width;
    Data::NextSizeY = height;
}

void Manager::ClearWindow()
{
    delete Data::CurrentWindow;
}

void Manager::SwitchWindow(WindowBase* newWindow)
{
    Data::CurrentWindow = newWindow;
}

void Manager::Render()
{
    const ImVec2 windowSize = { Data::NextSizeX, Data::NextSizeY };
    ImGui::SetNextWindowSize(windowSize);
    ImGui::SetNextWindowPos({ GetSystemMetrics(SM_CXSCREEN) / 2 - windowSize.x / 2, GetSystemMetrics(SM_CYSCREEN) / 2 - windowSize.y / 2 }, ImGuiCond_FirstUseEver);
    ImGui::SetNextWindowBgAlpha(1.0f);

    constexpr ImGuiWindowFlags windowFlags = ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoResize;
    static bool draw = true;
    ImGui::Begin("  ", &draw, windowFlags);

    Data::CurrentWindow->Render();

    ImGui::End();

    if (!draw)
        Global::ShouldExit = true;
}