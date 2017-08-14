#include "player.h"

Player::Player()
{
    playList = new QMediaPlaylist();

    setPlaylist(playList);
}
