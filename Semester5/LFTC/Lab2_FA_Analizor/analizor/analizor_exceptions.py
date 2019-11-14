class NotFoundException(Exception):
    """
    Class for atom not found exception
    """

    def __init__(self, exc):
        self.__exc = exc

    def get_exception(self):
        return self.__exc


class LiteralTooLongException(Exception):
    """
    Class for atoms which are too long
    """
    def __init__(self, exc):
        self.__exc = exc

    def get_exception(self):
        return self.__exc
