class LiteralNotInAlphabetException(Exception):
    """
    Class for throwing exceptions
    This exception is Thrown when the FA reads a literal which is not in the albhabet
    """

    def __init__(self, exc):
        self.__exc = exc

    def get_exc(self):
        return self.__exc
