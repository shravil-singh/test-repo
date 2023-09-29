package Tic_Tac_Toe;

import java.util.Scanner;

public class TicTacToe {
    private Player player1, player2;
    private Board board;
    private int numPlayer;

    public static void main(String[] args) {
        TicTacToe t = new TicTacToe();
        t.startGame();
    }

    public void startGame() {
        Scanner s = new Scanner(System.in);
        this.player1 = takePlayerInput(++numPlayer);
        this.player2 = takePlayerInput(++numPlayer);
        while (player1.getSymbol() == player2.getSymbol()) {
            System.out.println("Symbol already entered, please enter a new symbol.");
            player2.setSymbol(s.next().charAt(0));
        }
        boolean player1Turn = true;
        board = new Board(player1.getSymbol(), player2.getSymbol());
        int status = Board.INCOMPLETE;
        while (status == Board.INCOMPLETE || status == Board.INVALIDMOVE) {
            if (player1Turn) {
                System.out.println("Player 1 - " + player1.getName() + "'s turn");
                System.out.println("Enter x : ");
                int x = s.nextInt();
                System.out.println("Enter y : ");
                int y = s.nextInt();
                status = board.move(player1.getSymbol(), x, y);
                if (status == Board.INVALIDMOVE) {
                    System.out.println("Invalid move, please try again.");
                } else {
                    player1Turn = false;
                }
            } else {
                System.out.println("Player 2 - " + player2.getName() + "'s turn");
                System.out.println("Enter x : ");
                int x = s.nextInt();
                System.out.println("Enter y : ");
                int y = s.nextInt();
                status = board.move(player2.getSymbol(), x, y);
                if (status == Board.INVALIDMOVE) {
                    System.out.println("Invalid move, please try again.");
                } else {
                    player1Turn = true;
                }
            }
            board.print();
        }
        if (status == Board.PLAYER1WINS) {
            System.out.println("Player 1 - " + player1.getName() + " wins !");
        } else if (status == Board.PLAYER2WINS) {
            System.out.println("Player 2 - " + player2.getName() + " wins");
        } else {
            System.out.println("The game is a draw.");
        }
        s.close();
    }

    private Player takePlayerInput(int num) {
        Scanner s = new Scanner(System.in);
        System.out.println("Enter Player " + num + " name : ");
        String name = s.nextLine();
        System.out.println("Enter Player " + num + " symbol : ");
        char symbol = s.next().charAt(0);
        Player p = new Player(name, symbol);
        s.close();
        return p;
    }
}
