#pragma once

enum class GameState{
    MAIN_MENU,
    SCENE,
    GAME_OVER_MESSAGE,
    NEW_GAME,
    VICTORY_MESSAGE
};

enum class SceneState {
    INACTIVE,
    ACTIVE,
    DEFEAT
};