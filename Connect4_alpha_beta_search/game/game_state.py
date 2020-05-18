from board import BoardUtils
from board import IBuilder
from board.piece.piece import Piece
from player.alliance_enum import Alliance
from player.player import Player


class GameState:
    """
    Class for representing our game state
    """

    def __init__(self, board_builder: IBuilder, next_player: Player):
        """
        Constructor for game state class
        :param board_builder: game sate's board builder
        :param next_player: next player to make a move
        """
        self.__board_builder = board_builder
        self.__next_player = next_player

    @property
    def board_builder(self) -> IBuilder:
        return self.__board_builder

    @board_builder.setter
    def board_builder(self, new_board_builder: IBuilder):
        self.__board_builder = new_board_builder

    @property
    def valid_moves(self):
        return self.__board_builder.valid_moves

    @property
    def next_player(self):
        return self.__next_player

    @next_player.setter
    def next_player(self, new_player: Player):
        self.__next_player = new_player

    @property
    def evaluate_board(self) -> int:
        """
        Function to evaluate the board from the perspective of the player
        who is ntext to move
        :return: board score
        """
        player = self.__next_player
        utility = 0
        util_table = BoardUtils.get_utility_table()
        player_piece_type = Piece.BLUE if player.alliance == Alliance.BLUE else Piece.RED
        table = self.board_builder.board_config
        for line in range(len(table)):
            for col in range(len(table[0])):
                if table[line][col] == player_piece_type:
                    utility += util_table[line][col]
                elif table[line][col] != Piece.EMPTY:
                    utility -= util_table[line][col]
        return utility

    def __str__(self) -> str:
        """
        String representation of the game state
        :return: string representing the game state
        """
        return f"{self.board_builder}-{self.__next_player}"
