from copy import deepcopy
from typing import Optional

from board import Connect4BoardBuilder
from board.piece.piece import Piece
from game.game_state import GameState
from game.memento.I_memento import IMemento
from game.memento.connect4_memento import Connect4Memento
from player.alliance_enum import Alliance
from player.player import Player
from utils.utils import check_game_over


class GameManager:
    """
    Class representing the game manager
    """

    def __init__(self, player1: Player, player2: Player):
        self.__player1 = player1
        self.__player2 = player2
        self.__board_builder = Connect4BoardBuilder()
        self.__game_state = GameState(self.__board_builder, player1)

    def make_move(self, move: int) -> Optional[Player]:
        """
        Function to perform a move
        :param move: move to be performed
        :return: The winner if the game is over None otherwise
        """
        current_player = self.__game_state.next_player
        if current_player.alliance == Alliance.RED:
            current_piece = Piece.RED
        else:
            current_piece = Piece.BLUE
        self.__board_builder.set_piece(current_piece, move)
        self.__game_state.board_builder = self.__board_builder
        if self.game_over:
            return current_player
        if current_player == self.__player1:
            self.__game_state.next_player = self.__player2
        else:
            self.__game_state.next_player = self.__player1
        return None

    def make_move_new_state(self, move: int):
        """
        Function to perform a move
        :param move: move to be performed
        :return: A new Game Manager
        """
        new_gm = deepcopy(self)
        new_gm.make_move(move)
        return new_gm

    @property
    def player1(self):
        return self.__player1

    @property
    def player2(self):
        return self.__player2

    @property
    def game_over(self):
        return check_game_over(self.__game_state.board_builder.board_config)

    @property
    def draw(self):
        return len(self.state.valid_moves) == 0

    @property
    def state(self):
        return self.__game_state

    def save(self) -> IMemento:
        """
        Save the current state inside a memento
        :return: a new Connect4 memento
        """
        return Connect4Memento(self.__game_state)

    def restore(self, memento: IMemento) -> None:
        self.__game_state = memento.get_state()
        self.__board_builder = memento.get_state().board_builder

    def __str__(self):
        # COMPLETE THIS
        return f"{self.__game_state.board_builder.build()}"
