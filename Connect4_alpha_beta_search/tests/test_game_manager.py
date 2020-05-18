"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   17.05.2020 23:52
"""
from game.game_manager import GameManager


def test_game_manager(game: GameManager):
    game.make_move(0)
    game.make_move(1)
    game.make_move(0)
    game.make_move(1)
    game.make_move(0)
    assert game.make_move(1) is None
    assert game.make_move(0) is game.state.next_player
