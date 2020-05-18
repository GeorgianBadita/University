from board import Connect4BoardBuilder
from board.piece.piece import Piece
from utils.utils import check_game_over


def test_game_over():
    board_builder = Connect4BoardBuilder()
    board_builder.set_piece(Piece.RED, 0)
    board_builder.set_piece(Piece.RED, 0)
    board_builder.set_piece(Piece.RED, 0)
    board_builder.set_piece(Piece.RED, 0)
    assert check_game_over(board_builder.board_config) is True
    board_builder.clear()
    assert check_game_over(board_builder.board_config) is False
    board_builder.set_piece(Piece.RED, 6)
    board_builder.set_piece(Piece.RED, 5)
    board_builder.set_piece(Piece.RED, 4)
    board_builder.set_piece(Piece.BLUE, 3)
    board_builder.set_piece(Piece.BLUE, 2)
    board_builder.set_piece(Piece.BLUE, 1)
    assert check_game_over(board_builder.board_config) is False
    board_builder.set_piece(Piece.BLUE, 0)
    assert check_game_over(board_builder.board_config) is True
    board_builder.clear()
    board_builder.set_piece(Piece.BLUE, 2)
    board_builder.set_piece(Piece.BLUE, 2)
    board_builder.set_piece(Piece.RED, 2)
    board_builder.set_piece(Piece.RED, 2)
    board_builder.set_piece(Piece.RED, 2)
    board_builder.set_piece(Piece.RED, 2)
    assert check_game_over(board_builder.board_config) is True
    board_builder.clear()
    board_builder.set_piece(Piece.BLUE, 4)
    board_builder.set_piece(Piece.RED, 5)
    board_builder.set_piece(Piece.BLUE, 3)
    board_builder.set_piece(Piece.RED, 6)
    board_builder.set_piece(Piece.BLUE, 2)
    board_builder.set_piece(Piece.BLUE, 2)
    board_builder.set_piece(Piece.RED, 1)
    board_builder.set_piece(Piece.BLUE, 1)
    board_builder.set_piece(Piece.BLUE, 1)
    board_builder.set_piece(Piece.RED, 0)
    board_builder.set_piece(Piece.RED, 0)
    board_builder.set_piece(Piece.RED, 0)
    board_builder.set_piece(Piece.BLUE, 0)
    assert check_game_over(board_builder.board_config) is True
