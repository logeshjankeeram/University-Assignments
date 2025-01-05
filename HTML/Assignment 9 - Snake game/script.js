const canvas = document.getElementById('game');
const ctx = canvas.getContext('2d');

const gridSize = 20;
canvas.width = gridSize * 20;
canvas.height = gridSize * 20;

let snake = [{ x: 10, y: 10 }];
let fruit = getNewFruitPosition();
let direction = { x: 0, y: 0 }; // Start still
let grow = false;
let target = { x: 10, y: 10 }; // Target point for the cursor
let gameStarted = false; // Flag to check if the game has started

function drawRect(x, y, color) {
    ctx.fillStyle = color;
    ctx.fillRect(x * gridSize, y * gridSize, gridSize - 1, gridSize - 1);
}

function getNewFruitPosition() {
    let newFruit;
    do {
        newFruit = { x: Math.floor(Math.random() * 20), y: Math.floor(Math.random() * 20) };
    } while (snake.some(segment => segment.x === newFruit.x && segment.y === newFruit.y));
    return newFruit;
}

function moveSnakeTowardsTarget() {
    if (target.x > snake[0].x) direction = { x: 1, y: 0 };
    else if (target.x < snake[0].x) direction = { x: -1, y: 0 };
    else if (target.y > snake[0].y) direction = { x: 0, y: 1 };
    else if (target.y < snake[0].y) direction = { x: 0, y: -1 };
}

function updateGame() {
    if (!gameStarted) return; // Do nothing if the game hasn't started

    moveSnakeTowardsTarget();

    const head = { x: snake[0].x + direction.x, y: snake[0].y + direction.y };

    if (head.x < 0 || head.x >= canvas.width / gridSize || head.y < 0 || head.y >= canvas.height / gridSize || snake.some(segment => segment.x === head.x && segment.y === head.y)) {
        alert('Game Over!');
        snake = [{ x: 10, y: 10 }];
        direction = { x: 0, y: 0 }; // Reset to still
        fruit = getNewFruitPosition();
        gameStarted = false; // Reset the game state
        return;
    }

    snake.unshift(head);
    if (head.x === fruit.x && head.y === fruit.y) {
        fruit = getNewFruitPosition();
        grow = true;
    }

    if (!grow) {
        snake.pop();
    }
    grow = false;
}

function drawGame() {
    ctx.clearRect(0, 0, canvas.width, canvas.height);
    drawRect(fruit.x, fruit.y, 'red');
    snake.forEach(segment => drawRect(segment.x, segment.y, 'lime'));
}

canvas.addEventListener('mousemove', e => {
    const rect = canvas.getBoundingClientRect();
    const mouseX = e.clientX - rect.left;
    const mouseY = e.clientY - rect.top;
    target = {
        x: Math.floor(mouseX / gridSize),
        y: Math.floor(mouseY / gridSize),
    };
    gameStarted = true; // Start the game on mouse movement
});

function gameLoop() {
    updateGame();
    drawGame();
}

setInterval(gameLoop, 200);