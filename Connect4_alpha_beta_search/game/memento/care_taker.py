from game.game_manager import GameManager


class Caretaker:
    """
    Class representing the memento caretaker
    """

    def __init__(self, connect_4_game: GameManager):
        self.__connect_4_game = connect_4_game
        self.__mementos = []

    def backup(self) -> None:
        """
        Function to backup a game state
        :return:
        """
        self.__mementos.append(self.__connect_4_game.save())

    def undo(self) -> None:

        if not len(self.__mementos):
            return
        memento = self.__mementos.pop()
        self.__connect_4_game.restore(memento)

    def show_history(self) -> None:
        for memento in self.__mementos:
            print(memento.get_name())
