from typing import List

from board.I_builder import IBuilder
from board.board import Board
from board.board_utils import BoardUtils
from board.piece.piece import Piece
from exceptions.column_occupied_exception import ColumnOccupiedException
from exceptions.invalid_move_exception import InvalidMoveException


class Connect4BoardBuilder(IBuilder):
    """
    Board configuration
    """

    def __init__(self):
        self.__board_config = BoardUtils.get_default_board()

    @property
    def board_config(self) -> List[List[Piece]]:
        return self.__board_config

    @board_config.setter
    def board_config(self, new_board: Board):
        self.__board_config = new_board

    def clear(self):
        self.__board_config = BoardUtils.get_default_board()

    @property
    def valid_moves(self):
        """
        Function to get valid moves of the table
        :return:
        """
        valid_moves = []
        for col in range(BoardUtils.WIDTH):
            for line in range(BoardUtils.HEIGHT - 1, -1, -1):
                if self.board_config[line][col] == Piece.EMPTY:  # free position found
                    valid_moves.append(col)
                    break

        return valid_moves

    def set_piece(self, piece: Piece, index: int):
        """
        Function to set a new piece on the table
        :param piece: new piece to be put on the table
        :param index: column where to put the piece
        :return: Builder object
        """
        if index < 0 or index > BoardUtils.WIDTH:
            raise InvalidMoveException(str(index) + " is greater than " + str(BoardUtils.WIDTH) + " or is negative")
        found_pos = False
        for i in range(BoardUtils.HEIGHT - 1, -1, -1):
            if self.board_config[i][index] == Piece.EMPTY:  # free position found
                self.board_config[i][index] = piece  # put the piece on the table
                found_pos = True
                break
        if not found_pos:
            raise ColumnOccupiedException("Column already occupied")
        return self

    def build(self) -> Board:
        """
        Function to build a board
        :return: a new Board
        """
        return Board(self)

    def __str__(self):
        """
        String representation of the board_builder
        :return:
        """
        return str(self.build())
