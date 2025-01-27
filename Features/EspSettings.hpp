#pragma once
#include "../imgui/imgui.h"
#include "../Utils/SettingsContext.hpp"
#include "../RenderEngine/Renderer.hpp"
#include "../Math/Color.hpp"

enum class GlowType : int {
    DynamicColorGlow = 0,
    StaticColorGlow = 1,
    BasicGlow = 2
};

struct EspSettings
{
private:

    static const std::string tracersEnabledId;
    static const std::string tracersThicknessId;
    static const std::string tracersColorId;
    static const std::string tracersColorVisibleId;

    static const std::string espBoxColorId;
    static const std::string espBoxColorVisibleId;

    static const std::string glowEnabledId;
    static const std::string glowModeEnabledId;
    static const std::string glowTypeId;
    static const std::string glowRangeInMetersId;
    static const std::string glowStaticColorId;
    static const std::string glowMaxShieldColorId;
    static const std::string glowMinShieldColorId;
    static const std::string glowMaxHealthColorId;
    static const std::string glowMinHealthColorId;
    static const std::string glowTransparentLevelId;
    static const std::string glowBorderId;

    static const std::string espEnabledId;
    static const std::string espRangeInMetersId;

    bool _glowEnabled;
    bool _glowModeEnabled;
    GlowType _glowType;
    float _glowRangeInMeters;
    byte _glowTransparentLevel;
    byte _glowBorder;
    Color _glowStaticColor;
    Color _glowMaxShieldColor;
    Color _glowMinShieldColor;
    Color _glowMaxHealthColor;
    Color _glowMinHealthColor;

    bool _espEnabled;
    float _espRangeInMeters;

    bool _espBox;
    Color _espBoxColor;
    Color _espBoxColorVisible;

    bool _espHpShealds;



    bool _drawTracers;
    float _tracersThickness;
    Color _tracersColor;
    Color _tracersColorVisible;

    bool _drawFov;
    float _fovRadius;
    Color _fovColor;


public:
    EspSettings() :
        _glowEnabled(true),
        _glowModeEnabled(false),
        _glowType(GlowType::DynamicColorGlow),
        _glowRangeInMeters(1000),
        _glowTransparentLevel(90),
        _glowBorder(46),
        _glowStaticColor(1.0f, 1.0f, 1.0f),
        _glowMaxShieldColor(0.0f, 0.0f, 1.0f),
        _glowMinShieldColor(1.0f, 1.0f, 1.0f),
        _glowMaxHealthColor(0.0f, 1.0f, 0.0f),
        _glowMinHealthColor(1.0f, 0.0f, 0.0f),
        _espEnabled(false),
        _espBox(true),
        _espBoxColor(1.0f, 1.0f, 1.0f),
        _espBoxColorVisible(0.0f, 1.0f, 0.0f),
        _espHpShealds(true),
        _drawTracers(false),
        _tracersThickness(1.0f),
        _tracersColorVisible(0.0f, 1.0f, 0.0f),
        _tracersColor(1.0f, 1.0f, 1.0f),
        _drawFov(false),
        _fovColor(1.0f, 0.0f, 0.0f),
        _espRangeInMeters(100) {}

    bool isGlowEnabled() const {
        return _glowEnabled;
    }

    Color espBoxColor() const {
        return _espBoxColor;
    }

    Color espBoxColorVisible() const {
        return _espBoxColorVisible;
    }


    bool isEspBoxEnabled() const {
        return _espBox;
    }

    bool isEspHpShealdsEnabled() const {
        return _espHpShealds;
    }

    Color fovColor() const {
        return _fovColor;
    }

    float fovRadius() const {
        return _fovRadius;
    }

    bool drawFov() const {
        return _drawFov;
    }

    Color tracersColorVisible() const {
        return _tracersColorVisible;
    }

    Color tracersColor() const {
        return _tracersColor;
    }

    bool isTracersEnabled() const {
        return _drawTracers;
    }

    float tracersThickness() const{
        return _tracersThickness;
    }

    bool isGlowModeEnabled() const {
        return _glowModeEnabled;
    }

    float glowRangeInMeters() const {
        return _glowRangeInMeters;
    }

    byte getGlowTransparentLevel() const {
        return _glowTransparentLevel;
    }

    byte getGlowBorder() const {
        return _glowBorder;
    }

    GlowType getGlowType() const {
        return _glowType;
    }

    Color getGlowStaticColor() const {
        return _glowStaticColor;
    }

    Color getGlowMaxShieldColor() const {
        return _glowMaxShieldColor;
    }

    Color getGlowMinShieldColor() const {
        return _glowMinShieldColor;
    }

    Color getGlowMaxHealthColor() const {
        return _glowMaxHealthColor;
    }

    Color getGlowMinHealthColor() const {
        return _glowMinHealthColor;
    }

    bool isEspEnabled() const {
        return _espEnabled;
    }

    float getEspRangeInMeters() const {
        return _espRangeInMeters;
    }

    void render() {
        if(ImGui::BeginTabItem("ESP Settings")) {
	    ImGui::Checkbox("Tracers", &_drawTracers);
	    if (_drawTracers) {
	       Renderer::renderImguiColorValue("Tracers Color Visible", "ESP", _tracersColorVisible);
         Renderer::renderImguiColorValue("Tracers Color", "ESP", _tracersColor);

               ImGui::SliderFloat("Tracers Thickness", &_tracersThickness, 0.5f, 5.f, "%.2f");
               }
            ImGui::Checkbox("FOV Circle", &_drawFov);
            if (_drawFov) {
               Renderer::renderImguiColorValue("FOV Color", "ESP", _fovColor);
            }
            ImGui::Checkbox("Glow##ESP", &_glowEnabled);
            Renderer::renderImguiFloatValue("Glow range in meters", "ESP", &_glowRangeInMeters, 25.0f, 10000.0f, 1.0f, 50.0f);

            const char* glowTypes[] = { "Dynamic color", "Static color", "Basic" };
            int glowType = static_cast<int>(_glowType);
            ImGui::Combo("Glow type##ESP", &glowType, glowTypes, IM_ARRAYSIZE(glowTypes));
            _glowType = static_cast<GlowType>(glowType);

            if(_glowType != GlowType::BasicGlow) {
                ImGui::Checkbox("Glow mode(sets transparen level and border size)##ESP", &_glowModeEnabled);

                if(_glowModeEnabled) {
                    int glowTransparentLevel = _glowTransparentLevel;
                    if(Renderer::renderImguiIntValue("Glow transparent level", "ESP", &glowTransparentLevel, 1.0, 255, 1, 10)) {
                        _glowTransparentLevel = std::clamp(glowTransparentLevel, 0, 255);
                    }

                    int glowBorder = _glowBorder;
                    if(Renderer::renderImguiIntValue("Glow border", "ESP", &glowBorder, 1.0, 255, 1, 10)) {
                        _glowBorder = std::clamp(glowBorder, 0, 255);
                    }
                }

                if(_glowType == GlowType::DynamicColorGlow) {
                    Renderer::renderImguiColorValue("Glow max shield color", "ESP", _glowMaxShieldColor);
                    Renderer::renderImguiColorValue("Glow min shield color", "ESP", _glowMinShieldColor);
                    Renderer::renderImguiColorValue("Glow max health color", "ESP", _glowMaxHealthColor);
                    Renderer::renderImguiColorValue("Glow min health color", "ESP", _glowMinHealthColor);
                }
                else {
                    Renderer::renderImguiColorValue("Glow color", "ESP", _glowStaticColor);
                }
            }

            ImGui::Checkbox("Esp enabled##ESP", &_espEnabled);
            if (_espEnabled) {
              ImGui::Checkbox("Box##ESP", &_espBox);
              if (_espBox) {
                Renderer::renderImguiColorValue("Box Color Visible", "ESP", _espBoxColorVisible);
                Renderer::renderImguiColorValue("Box Color", "ESP", _espBoxColor);
              }
              ImGui::Checkbox("Hp&Shields##ESP", &_espHpShealds);
            }
            Renderer::renderImguiFloatValue("Esp range in meters", "ESP", &_espRangeInMeters, 25.0f, 500.0f, 1.0f, 25.0f);
            ImGui::EndTabItem();
        }
    }

    void load(const SettingsContext& settingsContext) {
        if(!settingsContext.loadBool(glowEnabledId, _glowEnabled)) {
            _glowEnabled = true;
        }

        if (!settingsContext.loadBool(tracersEnabledId, _drawTracers)) {
            _drawTracers = false;
        }

        if (!settingsContext.loadFloat(tracersThicknessId, _tracersThickness)) {
            _tracersThickness = 1.0f;
        }

        if (!settingsContext.loadVector(tracersColorId, (float*)&_tracersColor, Color::size)) {
            _tracersColor = Color(1.0f, 1.0f, 1.0f);
        }

        if (!settingsContext.loadVector(tracersColorVisibleId, (float*)&_tracersColorVisible, Color::size)) {
            _tracersColorVisible = Color(0., 1.0f, 0.0f);
        }

        if (!settingsContext.loadVector(espBoxColorId, (float*)&_espBoxColor, Color::size)) {
          _espBoxColor = Color(1.0f, 1.0f, 1.0f);
        }

        if (!settingsContext.loadVector(espBoxColorVisibleId, (float*)&_espBoxColorVisible, Color::size)) {
          _espBoxColorVisible = Color(0.0f, 1.0f, 0.0f);
        }


        if(!settingsContext.loadBool(glowModeEnabledId, _glowModeEnabled)) {
            _glowModeEnabled = false;
        }

        int glowTypeValue = 0;
        if(settingsContext.loadInt(glowTypeId, glowTypeValue)) {
            _glowType = static_cast<GlowType>(glowTypeValue);
        }
        else {
            _glowType = GlowType::DynamicColorGlow;
        }

        if(!settingsContext.loadFloat(glowRangeInMetersId, _glowRangeInMeters)) {
            _glowRangeInMeters = 1000;
        }

        if(!settingsContext.loadVector(glowStaticColorId, (float*)&_glowStaticColor, Color::size)) {
            _glowStaticColor = Color(1.0f, 1.0f, 1.0f);
        }

        if(!settingsContext.loadVector(glowMaxShieldColorId, (float*)&_glowMaxShieldColor, Color::size)) {
            _glowMaxShieldColor = Color(0.0f, 0.0f, 1.0f);
        }

        if(!settingsContext.loadVector(glowMinShieldColorId, (float*)&_glowMinShieldColor, Color::size)) {
            _glowMinShieldColor = Color(1.0f, 1.0f, 1.0f);
        }

        if(!settingsContext.loadVector(glowMaxHealthColorId, (float*)&_glowMaxHealthColor, Color::size)) {
            _glowMaxHealthColor = Color(0.0f, 1.0f, 0.0f);
        }

        if(!settingsContext.loadVector(glowMinHealthColorId, (float*)&_glowMinHealthColor, Color::size)) {
            _glowMinHealthColor = Color(1.0f, 0.0f, 0.0f);
        }

        if(!settingsContext.loadByte(glowTransparentLevelId, _glowTransparentLevel)) {
            _glowTransparentLevel = 90;
        }

        if(!settingsContext.loadByte(glowBorderId, _glowBorder)) {
            _glowBorder = 46;
        }

        if(!settingsContext.loadBool(espEnabledId, _espEnabled)) {
            _espEnabled = false;
        }

        if(!settingsContext.loadFloat(espRangeInMetersId, _espRangeInMeters)) {
            _espRangeInMeters = 100.0f;
        }
    }

    void save(SettingsContext& settingsContext) const {

        settingsContext.set(tracersEnabledId, _drawTracers);
        settingsContext.set(tracersThicknessId, _tracersThickness);
        settingsContext.set(tracersColorId, (float*)&_tracersColor, Color::size);
        settingsContext.set(tracersColorVisibleId, (float*)&_tracersColorVisible, Color::size);

        settingsContext.set(espBoxColorId, (float*)&_espBoxColor, Color::size);
        settingsContext.set(espBoxColorVisibleId, (float*)&_espBoxColorVisible, Color::size);

        settingsContext.set(glowEnabledId, _glowEnabled);
        settingsContext.set(glowModeEnabledId, _glowModeEnabled);
        settingsContext.set(glowTypeId, static_cast<int>(_glowType));
        settingsContext.set(glowRangeInMetersId, _glowRangeInMeters);
        settingsContext.set(glowStaticColorId, (float*)&_glowStaticColor, Color::size);
        settingsContext.set(glowMaxShieldColorId, (float*)&_glowMaxShieldColor, Color::size);
        settingsContext.set(glowMinShieldColorId, (float*)&_glowMinShieldColor, Color::size);
        settingsContext.set(glowMaxHealthColorId, (float*)&_glowMaxHealthColor, Color::size);
        settingsContext.set(glowMinHealthColorId, (float*)&_glowMinHealthColor, Color::size);
        settingsContext.set(glowTransparentLevelId, _glowTransparentLevel);
        settingsContext.set(glowBorderId, _glowBorder);

        settingsContext.set(espEnabledId, _espEnabled);
        settingsContext.set(espRangeInMetersId, _espRangeInMeters);
    }
};
//glowTransparentLevelId
const std::string EspSettings::tracersEnabledId = "esp.tracersEnabled";
const std::string EspSettings::tracersThicknessId = "esp.tracersThickness";
const std::string EspSettings::tracersColorId = "esp.tracersColor";
const std::string EspSettings::tracersColorVisibleId = "esp.tracersColorVisible";

const std::string EspSettings::espBoxColorId = "esp.espBoxColor";
const std::string EspSettings::espBoxColorVisibleId = "esp.espBoxColorVisible";

const std::string EspSettings::glowEnabledId = "esp.glowEnabled";
const std::string EspSettings::glowModeEnabledId = "esp.glowModeEnabled";
const std::string EspSettings::glowTypeId = "esp.glowType";
const std::string EspSettings::glowRangeInMetersId = "esp.glowRangeInMeters";
const std::string EspSettings::glowStaticColorId = "esp.glowStaticColor";
const std::string EspSettings::glowMaxShieldColorId = "esp.glowMaxShieldColor";
const std::string EspSettings::glowMinShieldColorId = "esp.glowMinShieldColor";
const std::string EspSettings::glowMaxHealthColorId = "esp.glowMaxHealthColor";
const std::string EspSettings::glowMinHealthColorId = "esp.glowMinHealthColor";
const std::string EspSettings::glowTransparentLevelId = "esp.glowTransparentLevel";
const std::string EspSettings::glowBorderId = "esp.glowBorderId";

const std::string EspSettings::espEnabledId = "esp.espEnabled";
const std::string EspSettings::espRangeInMetersId = "esp.espRangeInMeters";
