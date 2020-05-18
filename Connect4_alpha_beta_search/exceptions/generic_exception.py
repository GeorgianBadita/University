class GenericException(Exception):
    """
    Base class for exceptions
    """

    def __init__(self, msg: str):
        self.__exc_message = msg

    def get_exc(self) -> str:
        return self.__exc_message
