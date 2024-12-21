// Select necessary elements
const board = document.getElementById("board");
const statusDiv = document.getElementById("status");
const resetButton = document.getElementById("reset");

// Initialize the game state
let currentPlayer = "X";
let gameActive = true;
let boardState = Array(9).fill(null);

// Winning combinations
const winningCombos = [
    [0, 1, 2], [3, 4, 5], [6, 7, 8], // Rows
    [0, 3, 6], [1, 4, 7], [2, 5, 8], // Columns
    [0, 4, 8], [2, 4, 6],            // Diagonals
];

// Create the game board
function createBoard() {
    board.innerHTML = ""; // Clear previous board
    boardState.forEach((_, index) => {
        const cell = document.createElement("div");
        cell.classList.add("cell");
        cell.dataset.index = index;
        board.appendChild(cell);
    });
}

// Check for a winner or a draw
function checkGameStatus() {
    let roundWon = false;

    // Check all winning combinations
    for (const combo of winningCombos) {
        const [a, b, c] = combo;
        if (boardState[a] && boardState[a] === boardState[b] && boardState[a] === boardState[c]) {
            roundWon = true;
            break;
        }
    }

    if (roundWon) {
        statusDiv.textContent = `Player ${currentPlayer} wins! 🎉`;
        gameActive = false;
        return;
    }

    // Check for a draw
    if (!boardState.includes(null)) {
        statusDiv.textContent = "It's a draw! 🤝";
        gameActive = false;
        return;
    }

    // Switch turns
    currentPlayer = currentPlayer === "X" ? "O" : "X";
    statusDiv.textContent = `Player ${currentPlayer}'s turn`;
}

// Handle cell clicks
function handleCellClick(event) {
    const cell = event.target;
    const index = cell.dataset.index;

    if (boardState[index] || !gameActive) return;

    // Update the board state
    boardState[index] = currentPlayer;
    cell.textContent = currentPlayer;
    cell.classList.add("taken");

    // Check the game status
    checkGameStatus();
}

// Restart the game
function restartGame() {
    currentPlayer = "X";
    gameActive = true;
    boardState = Array(9).fill(null);
    statusDiv.textContent = `Player ${currentPlayer}'s turn`;
    createBoard();
}

// Add event listeners
board.addEventListener("click", handleCellClick);
resetButton.addEventListener("click", restartGame);

// Initialize the game
createBoard();
statusDiv.textContent = `Player ${currentPlayer}'s turn`;