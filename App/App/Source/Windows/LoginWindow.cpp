#include "../Global.h"

void LoginWindow::Render()
{
    Manager::SetNextSize(300.0f, 150.0f);

    ImVec2 windowSize = ImGui::GetWindowSize();

    constexpr float textBoxWidth = 250.0f;
    ImGui::PushItemWidth(textBoxWidth);
    ImGui::SetCursorPosX((windowSize.x - textBoxWidth) * 0.5f);
    ImGui::InputTextWithHint("##username", "username", UsernameField, IM_ARRAYSIZE(UsernameField));
    ImGui::Spacing();

    ImGui::SetCursorPosX((windowSize.x - textBoxWidth) * 0.5f);
    ImGui::InputTextWithHint("##password", "password", PasswordField, IM_ARRAYSIZE(PasswordField), ImGuiInputTextFlags_Password);
    ImGui::Spacing();
    ImGui::PopItemWidth();

    ImGui::SetCursorPosX((windowSize.x - textBoxWidth) * 0.5f);
    ImGui::Checkbox("remember", &RememberCredentials);

    ImGui::SameLine();
    constexpr float buttonWidth = 45.0f;
    const float buttonPosX = (windowSize.x - textBoxWidth) * 0.5f + textBoxWidth - buttonWidth;
    ImGui::SetCursorPosX(buttonPosX);
    if (ImGui::Button("login", ImVec2(buttonWidth, 0.0f)))
    {
        Manager::ClearWindow();
        auto* nextWindow = new MainWindow();
        Manager::SwitchWindow(nextWindow);
    }

    ImGui::Spacing();
}