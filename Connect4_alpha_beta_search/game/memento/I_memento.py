from abc import abstractmethod

from game.game_state import GameState


class IMemento:
    """
    The memento interface provides a way to retrieve the memento's metadata
    such as name or cretion date
    """

    @abstractmethod
    def get_name(self) -> str:
        pass

    @abstractmethod
    def get_date(self) -> str:
        pass

    @abstractmethod
    def get_state(self) -> GameState:
        pass