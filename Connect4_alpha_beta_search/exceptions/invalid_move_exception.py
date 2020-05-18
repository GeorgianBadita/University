from exceptions.generic_exception import GenericException


class InvalidMoveException(GenericException):

    def __init__(self, msg: str):
        super().__init__(msg)
