from typing import List

from board.piece.piece import Piece


class BoardUtils:
    WIDTH = 7
    HEIGHT = 6

    @staticmethod
    def get_default_board() -> List[List[Piece]]:
        return [[Piece.EMPTY for _ in range(BoardUtils.WIDTH)] for __ in range(BoardUtils.HEIGHT)]

    @staticmethod
    def get_utility_table() -> List[List[int]]:
        return [[3, 4, 5, 7, 5, 4, 3],
                [4, 6, 8, 10, 8, 6, 4],
                [5, 8, 11, 13, 11, 8, 5],
                [5, 8, 11, 13, 11, 8, 5],
                [4, 6, 8, 10, 8, 6, 4],
                [3, 4, 5, 7, 5, 4, 3]]
