"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   17.05.2020 23:53
"""

import pytest

from game.game_manager import GameManager
from player.alliance_enum import Alliance
from player.player import Player
from player.type_enum import PlayerType


@pytest.fixture
def player_red():
    return Player(Alliance.RED, PlayerType.HUMAN)


@pytest.fixture
def player_blue():
    return Player(Alliance.BLUE, PlayerType.HUMAN)


@pytest.fixture
def game(player_red, player_blue):
    return GameManager(player_red, player_blue)
