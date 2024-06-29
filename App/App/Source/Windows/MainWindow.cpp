#include "../Global.h"

void MainWindow::Render()
{
    Manager::SetNextSize(300.0f, 300.0f);

    const ImVec2 windowSize = ImGui::GetWindowSize();
    float buttonWidth = ((windowSize.x - ImGui::GetStyle().ItemSpacing.x * 2) / 3.0f) - ImGui::GetStyle().ItemSpacing.x;

    if (ImGui::Button("log out", ImVec2(buttonWidth, 0.0f)))
    {
        Manager::ClearWindow();
        auto* nextWindow = new LoginWindow();
        Manager::SwitchWindow(nextWindow);
    }
    ImGui::SameLine();

    if (ImGui::Button("web", ImVec2(buttonWidth, 0.0f)))
        ShellExecuteA(nullptr, "open", "https://tulach.cc/", nullptr, nullptr, SW_SHOWNORMAL);
    ImGui::SameLine();

    if (ImGui::Button("git", ImVec2(buttonWidth, 0.0f)))
        ShellExecuteA(nullptr, "open", "https://github.com/SamuelTulach/ImGui-AppKit", nullptr, nullptr, SW_SHOWNORMAL);

    ImGui::Separator();

    ImGui::Text("\n\n\n\n\n\n\n\n\n\n\n\n");

    ImGui::Separator();

    ImGui::Text("build on:");
    ImGui::SameLine();
    ImGui::Text(__DATE__);
    ImGui::SameLine();
    ImGui::Text(__TIME__);
}