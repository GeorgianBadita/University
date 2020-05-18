from player.alliance_enum import Alliance
from player.type_enum import PlayerType


class Player:

    def __init__(self, alliance: Alliance, player_type: PlayerType, name="Computer"):
        self.__player_type = player_type
        self.__alliance = alliance
        if player_type == PlayerType.HUMAN and name == "Computer":
            self.__name = "Human"
        else:
            self.__name = name

    @property
    def name(self) -> str:
        return self.__name

    @name.setter
    def name(self, new_name: str):
        self.__name = new_name

    @property
    def alliance(self) -> Alliance:
        return self.__alliance

    @alliance.setter
    def alliance(self, new_alliance: Alliance):
        self.__alliance = new_alliance

    @property
    def player_type(self) -> PlayerType:
        return self.__player_type

    @player_type.setter
    def player_type(self, new_type: PlayerType):
        self.__player_type = new_type

    def __eq__(self, other) -> bool:
        return self.__alliance == other.alliance and self.__name == other.name and self.__player_type == other.player_type

    def __str__(self) -> str:
        return f"{self.__name}-{self.__player_type}-{self.__alliance}"
