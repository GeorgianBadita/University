from alpha_beta.alpha_beta_pruning import alpha_beta
from game.game_manager import GameManager
from player.alliance_enum import Alliance
from player.player import Player
from player.type_enum import PlayerType

DEPTH = 8


def main():
    player1 = Player(Alliance.RED, PlayerType.HUMAN, name="Dia")
    player2 = Player(Alliance.BLUE, PlayerType.COMPUTER)

    gm = GameManager(player1, player2)
    winner = None
    while not gm.game_over and not gm.draw:
        print("TABLE: ")
        print(gm)
        if gm.state.next_player.player_type == PlayerType.HUMAN:
            while True:
                try:
                    move = int(input("Please give a number from 0 to 6: "))
                    break
                except ValueError:
                    print("INVALID MOVE, plese try again! :)")
        else:
            move = alpha_beta(gm, DEPTH)
            if move is None:
                return gm.state.valid_moves[0]
        winner = gm.make_move(move)

    print(gm)
    print(f"\nNice player: {winner.name} has won")


main()
