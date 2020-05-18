from typing import List

from board.piece.piece import Piece


class Color:
    """
    Color class to print colored text
    """
    PURPLE = '\033[95m'
    CYAN = '\033[96m'
    DARKCYAN = '\033[36m'
    BLUE = '\033[94m'
    GREEN = '\033[92m'
    YELLOW = '\033[93m'
    RED = '\033[91m'
    END = '\033[0m'
    BOLD = '\033[1m'

    COLOR_MAP = {
        "red": RED,
        "blue": BLUE,
        "cyan": CYAN,
        "green": GREEN,
        "yellow": YELLOW,
        "dark_cyan": DARKCYAN,
        "bold": BOLD,
        "end": END,
    }


def check_game_over(board_config: List[List[Piece]]) -> bool:
    """
    Function to check if a game is over
    :param board_config: board configuration
    :return: True if the game is over, False otherwise
    """

    # check horizontally
    for i in range(len(board_config)):
        for j in range(len(board_config[0])):
            if j + 3 < len(board_config[0]):
                if board_config[i][j] != Piece.EMPTY:
                    if board_config[i][j] == board_config[i][j + 1] == board_config[i][j + 2] == board_config[i][j + 3]:
                        return True

    # check vertically
    for j in range(len(board_config[0])):
        for i in range(len(board_config)):
            if i + 3 < len(board_config):
                if board_config[i][j] != Piece.EMPTY:
                    if board_config[i][j] == board_config[i + 1][j] == board_config[i + 2][j] == board_config[i + 3][j]:
                        return True

    # check diagonally
    for i in range(len(board_config)):
        for j in range(len(board_config[0])):
            if i + 3 < len(board_config) and j + 3 < len(board_config[0]):
                if board_config[i][j] != Piece.EMPTY:
                    if board_config[i][j] == board_config[i + 1][j + 1] == board_config[i + 2][j + 2] == \
                            board_config[i + 3][j + 3]:
                        return True
            if len(board_config) > i - 3 >= 0 and len(board_config[0]) > j - 3 >= 0:
                if board_config[i][j] != Piece.EMPTY:
                    if board_config[i][j] == board_config[i - 1][j - 1] == board_config[i - 2][j - 2] == \
                            board_config[i - 3][j - 3]:
                        return True

    return False
