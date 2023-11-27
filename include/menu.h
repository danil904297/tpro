#ifndef MainMenu_HPP
#define MainMenu_HPP

#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>

// #include "GameMode.hpp"
// #include "./Options/Options.hpp"
// #include "About.hpp"
 #include "Statistics.hpp"
// #include "ExitConfirmationWindow.hpp"

// #include "../StateStack/StateStack.hpp"
// #include "../Details/Button.hpp"
// #include "../Details/Text.hpp"


// #include "../Transition/ShaderTransition.hpp"

namespace game
{
class MainMenu : public State
{
private:
class Author : public IPopupWindow
{
private:
    struct DesignSettings
    {
        sf::Vector2f cancelButtonPosition = {75.f, 75.f};
        sf::FloatRect cancelButtonSize = {0.f, 0.f, 100.f, 100.f};
        float titlePositionOnOY = 45.f;
        sf::Color backgroundColor = sf::Color(249, 247, 239);
        float sizeBetweenTitleAndAuthor = 120.f;
        float sizeBetweenAuthors = 80.f;
        float margin = 100.f;
    } Decor;

    sf::RectangleShape _background;
    game::Text _title;

    std::vector<sf::Vector2<game::Text>> _authors;
    game::ButtonWithSprite _cancel;

    void init()
    {
        _background.setFillColor(Decor.backgroundColor);
        _background.setOutlineThickness(3.f);
        _background.setOutlineColor(sf::Color::Black);

        _authors.push_back
        ({
            TextOptions(L"Разработчик:", 64, sf::Color(56, 154, 70), "../Oks Free.otf", 4.f), 
            TextOptions(L"Дмитрий dub04ek Ватолин", 64, sf::Color(56, 154, 70), "../Oks Free.otf", 4.f)
        });
        _authors.push_back
        ({
            TextOptions(L"Тестировщик:", 48, sf::Color(56, 154, 70, 120), "../Oks Free.otf", 1.5f), 
            TextOptions(L"Александр pene4ek Алборов", 48, sf::Color(56, 154, 70, 120), "../Oks Free.otf", 1.5f)
        });
        _authors.push_back
        ({
            TextOptions(L"Участник:", 32, sf::Color(56, 154, 70, 90), "../Oks Free.otf", 0.5f), 
            TextOptions(L"Андрей Vamisino4kau Анисимов", 32, sf::Color(56, 154, 70, 90), "../Oks Free.otf", 0.5f)
        });
    }

    void Align()
    {
        _title.setPosition(_background.getSize().x / 2, Decor.titlePositionOnOY + _title.getGlobalBounds().height / 2.f);
        _cancel.SetPosition(Decor.cancelButtonPosition);

        float currentHeight = _title.getPosition().y + _title.getGlobalBounds().height / 2.f + Decor.sizeBetweenTitleAndAuthor;
        for (auto &&author : _authors)
        {
            author.x.setPosition(Decor.margin + author.x.getGlobalBounds().width / 2.f,
                                currentHeight + author.x.getGlobalBounds().height / 2.f);
            author.y.setPosition(_background.getSize().x - Decor.margin - author.y.getGlobalBounds().width / 2.f, 
                    author.x.getPosition().y);
                
            currentHeight += author.x.getGlobalBounds().height + Decor.sizeBetweenAuthors;
        }
        
    }

public:
    Author() = default;
    ~Author() {}

    Author(game::StateStack* stateStack)
        : IPopupWindow(stateStack), _background({1400, 660}),
        _title({L"Авторский коллектив", 80, sf::Color(239, 131, 67)}),
        _cancel({Decor.cancelButtonSize, 20, sf::Color(56, 154, 70), 
        [&]()
        {
            RequestStackPop();
            TransitAnimation(Direction::DownUp);
            
        }, sf::Sprite(AssetManager::GetTexture("../Images/Close/CloseDefault.png")), sf::Sprite(AssetManager::GetTexture("../Images/Close/CloseHover.png"))})
    {
        init();
        Align();
    };

    sf::Vector2f GetSize() const override
    {
        return _background.getSize();
    }

    void SetPosition(const sf::Vector2f& position) override
    {
        SetOffset(position.x - _background.getPosition().x, position.y - _background.getPosition().y);
    }

    void Draw(sf::RenderTarget* target) override
    {
        GetStateStack()->Penultimate()->Draw(target);
        target->draw(_blur);
        target->draw(_background);
        _cancel.Draw(target);
        target->draw(_title);
        for (auto &&author : _authors)
        {
            target->draw(author.x);
            target->draw(author.y);
        }
    }
    
    void Update(float dt) override
    {
        return;
    }

    void SetOffsetOnOY(float OYOffset) override
    {
        SetOffset(0, OYOffset);
    }

    void HandleEvent(const sf::Event& event, const sf::Vector2f& mousePositon) override
    {
        _cancel.Update(mousePositon, event);
    }

    void SetOffset(float OXOffset, float OYOffset)
    {
        _background.setPosition(_background.getPosition().x + OXOffset, _background.getPosition().y + OYOffset);
        _cancel.SetPosition(_cancel.getPosition().x + OXOffset, _cancel.getPosition().y + OYOffset);
        _title.setPosition(_title.getPosition().x + OXOffset, _title.getPosition().y + OYOffset);
        for (auto &&author : _authors)
        {
            author.x.setPosition(author.x.getPosition().x + OXOffset, author.x.getPosition().y + OYOffset);
            author.y.setPosition(author.y.getPosition().x + OXOffset, author.y.getPosition().y + OYOffset);
        }
    }
};
private:
    enum class ID
    {
        Play,
        Options,
        About,
        Archive,
        Statistics
    };

    struct MainMenuDesignSettings
    {
        const std::string fontFile = "../Fonts/Oks Free.otf";
        const float titlePositionOnOY = 80.f;
        const float stepBetweenButtons = 50.f;
        const sf::Color hoverTextColor = sf::Color::Black;
        const sf::Color defaultTextColor = sf::Color::White;
        const int titleFontSize = 128;

        std::vector<game::DecorativeStar> stars
        {
            {50.f, {1436, 100}, 46.f},
            {30.f, {1697, 220}, 20.f},
            {70.f, {1535, 200}, 47.f},
            {50.f, {1643, 500}},
            {30.f, {1321, 700}, 76.f},
            {30.f, {200, 134}, 32.f},
            {50.f, {435, 564}, 97.f},
            {30.f, {135, 220}, 23.f},
            {70.f, {496, 243}, 65.f},
            {50.f, {356, 915}},
            {50.f, {1650, 875}},
            {30.f, {263, 732}, 98.f},
            {30.f, {565, 141}, 55.f}
        };

    } Decor;

    game::Text _title;
    std::vector<game::ButtonWithText> _buttons;

    void init()
    {
        _buttons.push_back({sf::FloatRect(0.f, 0.f , 600.f, 100.f), 45.f, sf::Color(56, 154, 70), game::TextOptions(L"Играть"), 
        [&](){
            GetStateStack()->PushState(new game::GameMode(GetStateStack()));
            TransitAnimation(Direction::TopDown);

        }});
        
        _buttons.push_back({sf::FloatRect(0.f, 0.f , 600.f, 100.f), 45.f, sf::Color(56, 154, 70), game::TextOptions(L"Настройки"), 
        [&](){
            GetStateStack()->PushState(new game::Options(GetStateStack()));
            TransitAnimation(Direction::TopDown);

        }});

        _buttons.push_back({sf::FloatRect(0.f, 0.f , 600.f, 100.f), 45.f, sf::Color(56, 154, 70), game::TextOptions(L"Об игре"), 
        [&]()
        {
            Transition::Get()->SetFunction
            (
                [&]() 
                {
                    GetStateStack()->PushState(new game::About(GetStateStack()));
                    Transition::Get()->SetMode(ShaderMode::Unveil);
                }
            );
            Transition::Get()->SetMode(ShaderMode::Veil);
        }});

        _buttons.push_back({sf::FloatRect(0.f, 0.f , 600.f, 100.f), 45.f, sf::Color(56, 154, 70), game::TextOptions(L"Архив партий"), 
        [&]()
        {
            Transition::Get()->SetFunction
            (
                [&]() 
                {
                    GetStateStack()->PushState(new game::Statistics(GetStateStack()));
                    Transition::Get()->SetMode(ShaderMode::Unveil);
                }
            );
            Transition::Get()->SetMode(ShaderMode::Veil);
        }});

        _buttons.push_back({sf::FloatRect(0.f, 0.f , 600.f, 100.f), 45.f, sf::Color(56, 154, 70), game::TextOptions(L"Выход"), 
        [&](){
            auto state = new game::ExitConfirmationWindow(GetStateStack());
            GetStateStack()->PushState(state);
            state->TransitAnimation(Direction::TopDown);
        }});
    }

public:
    MainMenu(game::StateStack* stateStack)
        : game::State(stateStack), _title({L"Реверси", Decor.titleFontSize, sf::Color(239, 131, 67)}), _buttons()
    {
        init();
        Align();
    }

    ~MainMenu() override {};

    void AlignWidth()
    {
        _title.setPosition(GetRenderTexture()->getSize().x / 2, _title.getPosition().y);
        for (auto &button : _buttons)
        {
            button.SetPosition(GetRenderTexture()->getSize().x / 2, button.getPosition().y);
        }
    
    }

    void Align()
    {
        AlignWidth();
        _title.setPosition(_title.getPosition().x, Decor.titlePositionOnOY);

        float totalHeight = (_buttons.size() - 1) * Decor.stepBetweenButtons;
        for (auto &&button : _buttons)
        {
            totalHeight += button.getGlobalBounds().height;
        }

        float currentHeight = (GetRenderTexture()->getSize().y + Decor.titlePositionOnOY + _title.getGlobalBounds().height / 2.f - totalHeight) / 2.f;
        for (auto &button : _buttons)
        {
            currentHeight += button.getGlobalBounds().height / 2.f;
            button.SetPosition(button.getPosition().x, currentHeight);
            currentHeight += Decor.stepBetweenButtons + button.getGlobalBounds().height / 2.f;
        }
        
    }

    void Draw(sf::RenderTarget* target) override
    {
        sf::Vector2f mousePosition = GetWindow()->mapPixelToCoords(sf::Mouse::getPosition(*GetWindow()));
        if (GetStateStack()->Back() == this)
            for (auto &&button : _buttons)
                button.Update(mousePosition);

        target->draw(_title);
        for (auto &&button : _buttons)
            button.Draw(target);

        for (auto &star : Decor.stars)
            target->draw(star);
    }

    void SetOffsetOnOY(float OYOffset) override
    {
        _title.setPosition(_title.getPosition().x, _title.getPosition().y + OYOffset);

        for (auto &button : _buttons)
            button.SetPosition(button.getPosition().x, button.getPosition().y + OYOffset);
        
        for (auto &star : Decor.stars)
            star.setPosition(star.getPosition().x, star.getPosition().y + OYOffset);
        
    }
    void Update(float dt) override
    {
        for (auto &star : Decor.stars)
            star.Update(dt);
    }

    void HandleEvent(const sf::Event& event, const sf::Vector2f& mousePositon)
    {
        if (event.type == sf::Event::Closed)
        {
            RequestStateClear();
        }
        
        if (Decor.stars.back().getGlobalBounds().contains(mousePositon) && event.key.code == (int)sf::Mouse::Left)
        {
            auto state = new game::MainMenu::Author(GetStateStack());
            GetStateStack()->PushState(state);
            state->TransitAnimation(Direction::TopDown);
        }

        for (auto &button : _buttons)
            button.Update(mousePositon, event);
    }
};

} // end namespace game

#endif