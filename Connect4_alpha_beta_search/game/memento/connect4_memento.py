from datetime import datetime

from game.game_state import GameState
from game.memento.I_memento import IMemento


class Connect4Memento(IMemento):
    def __init__(self, state: GameState):
        """
        Constructor for Connect4Memento class
        :param state: State to be in the memento
        """
        self.__state = state
        self.__date = str(datetime.now())

    def get_state(self) -> GameState:
        return self.__state

    def get_name(self) -> str:
        return f"{self.__date}/({self.__state})"

    def get_date(self) -> str:
        return self.__date
