#pragma once

class LoginWindow : public WindowBase
{
private:
    char UsernameField[128];
    char PasswordField[128];
    bool RememberCredentials = true;

public:
    void Render() override;
};