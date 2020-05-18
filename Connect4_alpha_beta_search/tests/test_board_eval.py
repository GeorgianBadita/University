"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   17.05.2020 23:52
"""
from game.game_manager import GameManager


def test_board_eval(game: GameManager):
    game.make_move(0)
    game.make_move(1)
    game.make_move(2)
    game.make_move(2)
    game.make_move(1)
    game.make_move(1)
    game.make_move(0)
    assert game.state.evaluate_board == 2
    game.make_move(0)
    assert game.state.evaluate_board == -7
