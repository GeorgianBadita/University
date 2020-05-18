from abc import abstractmethod


class IBuilder:
    """
    Builder Interface
    """
    board_config = None

    @abstractmethod
    def build(self):
        """
        Function to build a board from the builder
        :return: Board
        """
        raise NotImplemented("Function build from IBuilder not implemented")

    @abstractmethod
    def valid_moves(self):
        """
        Function to return board's valid moves
        :return: valid moves of the board
        """
        raise NotImplemented("Function build from IBuilder not implemented")
