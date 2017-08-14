#include "player.h"

Player::Player()
{
    playList = new QMediaPlaylist();

    setPlaylist(playList);
}

bool Player::status()
{
    return state() == QMediaPlayer::PlayingState;
}
