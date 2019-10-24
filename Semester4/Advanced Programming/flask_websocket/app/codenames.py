import json


class Game:

    def __init__(self, id, teams):
        self.id = id
        self.teams = teams

    def flip_card(self, card):
        print("CARD FLIPPED")
        return card

    def to_json(self):
        return json.dumps({"id": self.id, "teams": self.teams})
