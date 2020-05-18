from board import Connect4BoardBuilder
from board.piece.piece import Piece
from exceptions.column_occupied_exception import ColumnOccupiedException
from exceptions.invalid_move_exception import InvalidMoveException
import pytest


def test_board():
    board_builder = Connect4BoardBuilder()
    with pytest.raises(InvalidMoveException) as exc_info:
        board_builder.set_piece(Piece.RED, -1)
        assert '-1' in exc_info
        assert '7' in exc_info
    board_builder.set_piece(Piece.RED, 0)
    board_builder.set_piece(Piece.RED, 0)
    board_builder.set_piece(Piece.RED, 0)
    board_builder.set_piece(Piece.RED, 0)
    board_builder.set_piece(Piece.RED, 0)
    board_builder.set_piece(Piece.RED, 0)
    with pytest.raises(ColumnOccupiedException) as exc_info:
        board_builder.set_piece(Piece.RED, 0)
        assert "occupied" in exc_info
