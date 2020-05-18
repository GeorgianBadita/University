from board.I_builder import IBuilder
from board.board_utils import BoardUtils
from board.piece.piece import Piece
from utils.utils import Color


class Board:
    """
    Class for representing our board
    """

    def __init__(self, builder: IBuilder):
        """
        Board constructor
        :param builder: board's builder
        """
        self.__table = self.__construct(builder)

    def __construct(self, builder: IBuilder):
        """
        Function to construct a board
        :param builder: builder which constructs the board
        :return: the board table
        """
        return builder.board_config

    def __str__(self) -> str:
        """
        String representation of the table
        :return:
        """
        string_board = ""
        for line in range(BoardUtils.HEIGHT):
            for col in range(BoardUtils.WIDTH):
                if self.__table[line][col] == Piece.RED:
                    string_board += Color.RED + Color.BOLD + "o" + Color.END + " "
                elif self.__table[line][col] == Piece.BLUE:
                    string_board += Color.BLUE + Color.BOLD + "o" + Color.END + " "
                else:
                    string_board += Color.BOLD + "o" + Color.END + " "
            string_board += "\n"
        return string_board
