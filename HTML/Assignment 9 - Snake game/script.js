const canvas = document.getElementById('game');
const ctx = canvas.getContext('2d');

const size = 20;
canvas.width = size * 20;
canvas.height = size * 20;

let snake = [{ x: 10, y: 10 }];
let fruit = newFruit();
let dir = { x: 0, y: 0 };
let grow = false;
let aim = { x: 10, y: 10 };
let started = false;

function draw(x, y, color) {
    ctx.fillStyle = color;
    ctx.fillRect(x * size, y * size, size - 1, size - 1);
}

function newFruit() {
    let f;
    do {
        f = { x: Math.floor(Math.random() * 20), y: Math.floor(Math.random() * 20) };
    } while (snake.some(part => part.x === f.x && part.y === f.y));
    return f;
}

function moveSnake() {
    if (aim.x > snake[0].x) dir = { x: 1, y: 0 };
    else if (aim.x < snake[0].x) dir = { x: -1, y: 0 };
    else if (aim.y > snake[0].y) dir = { x: 0, y: 1 };
    else if (aim.y < snake[0].y) dir = { x: 0, y: -1 };
}

function update() {
    if (!started) return;

    moveSnake();

    const head = { x: snake[0].x + dir.x, y: snake[0].y + dir.y };

    if (head.x < 0 || head.x >= canvas.width / size || head.y < 0 || head.y >= canvas.height / size || snake.some(part => part.x === head.x && part.y === head.y)) {
        alert('Game Over!');
        snake = [{ x: 10, y: 10 }];
        dir = { x: 0, y: 0 };
        fruit = newFruit();
        started = false;
        return;
    }

    snake.unshift(head);
    if (head.x === fruit.x && head.y === fruit.y) {
        fruit = newFruit();
        grow = true;
    }

    if (!grow) {
        snake.pop();
    }
    grow = false;
}

function drawGame() {
    ctx.clearRect(0, 0, canvas.width, canvas.height);
    draw(fruit.x, fruit.y, 'red');
    snake.forEach(part => draw(part.x, part.y, 'lime'));
}

canvas.addEventListener('mousemove', e => {
    const rect = canvas.getBoundingClientRect();
    const mx = e.clientX - rect.left;
    const my = e.clientY - rect.top;
    aim = {
        x: Math.floor(mx / size),
        y: Math.floor(my / size),
    };
    started = true;
});

function loop() {
    update();
    drawGame();
}

setInterval(loop, 200);
