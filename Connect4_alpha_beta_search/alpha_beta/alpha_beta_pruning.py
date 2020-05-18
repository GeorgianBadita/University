"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   17.05.2020 23:38
"""
from game.game_manager import GameManager


# TODO CLONE THE GM
def alpha_beta(state: GameManager, depth: int) -> float:
    moves = state.state.valid_moves
    best_move = None
    best_score = float('-inf')
    beta = float('inf')

    for move in moves:
        clone = state.make_move_new_state(move)
        score = minimize(clone, best_score, beta, depth - 1)
        if score > best_score:
            best_score = score
            best_move = move
        print(f"score: {score}")
    return best_move


def minimize(state: GameManager, alpha: float, beta: float, depth: int) -> float:
    # print(f"depth: {depth}")
    if state.game_over:
        return float('inf')
    if state.draw:
        return 0

    if depth == 0:
        return state.state.evaluate_board

    moves = state.state.valid_moves
    score = float('inf')
    for move in moves:
        clone = state.make_move_new_state(move)
        score = min(score, maximize(clone, alpha, beta, depth - 1))
        if score <= alpha:
            return score
        beta = min(beta, score)
    return score


def maximize(state: GameManager, alpha: float, beta: float, depth: int) -> float:
    if state.game_over:
        return float('-inf')
    if state.draw:
        return 0
    if depth == 0:
        return state.state.evaluate_board
    moves = state.state.valid_moves
    score = float('-inf')
    for move in moves:
        clone = state.make_move_new_state(move)
        score = max(score, minimize(clone, alpha, beta, depth - 1))
        if score >= beta:
            return score
        alpha = max(score, alpha)
    return score
