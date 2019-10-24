class NotFoundException(Exception):
    """
    Class for atom exception
    """
    def __init__(self, exc):
        self.__exc = exc

    def get_exception(self):
        return self.__exc
