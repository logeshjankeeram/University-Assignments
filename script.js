const data = [
  {
    title: "Diabetes Risk Prediction Project",
    description: "Deep learning model using BRFSS dataset",
    tags: ["AI", "ML", "health", "neural network"]
  },
  {
    title: "HTML Project 1",
    description: "Basic website layout with forms",
    tags: ["html", "css", "web"]
  },
  {
    title: "Excel Dashboard",
    description: "Dynamic KPI tracking dashboard",
    tags: ["excel", "data", "dashboard"]
  }
];

// ---------- render ----------
function render(items) {
  const container = document.getElementById("results");
  container.innerHTML = "";

  if (items.length === 0) {
    container.innerHTML = "<p>No results found.</p>";
    return;
  }

  items.forEach(item => {
    const div = document.createElement("div");
    div.className = "card";

    div.innerHTML = `
      <div class="title">${item.title}</div>
      <div>${item.description}</div>
      <div class="meta">${item.tags.join(" • ")}</div>
    `;

    container.appendChild(div);
  });
}

// ---------- scoring system (improved search logic) ----------
function scoreItem(item, query) {
  const q = query.toLowerCase();

  let score = 0;

  const title = item.title.toLowerCase();
  const desc = item.description.toLowerCase();
  const tags = item.tags.join(" ").toLowerCase();

  // exact match boost
  if (title === q) score += 100;

  // starts with boost
  if (title.startsWith(q)) score += 70;

  // includes boost
  if (title.includes(q)) score += 50;
  if (desc.includes(q)) score += 20;
  if (tags.includes(q)) score += 30;

  // word-by-word match
  const words = q.split(" ");
  words.forEach(w => {
    if (title.includes(w)) score += 15;
    if (desc.includes(w)) score += 8;
    if (tags.includes(w)) score += 10;
  });

  // fuzzy tolerance (simple)
  if (levenshtein(title, q) <= 3) score += 25;

  return score;
}

// ---------- lightweight fuzzy matching ----------
function levenshtein(a, b) {
  const matrix = Array.from({ length: b.length + 1 }, () => []);

  for (let i = 0; i <= b.length; i++) matrix[i][0] = i;
  for (let j = 0; j <= a.length; j++) matrix[0][j] = j;

  for (let i = 1; i <= b.length; i++) {
    for (let j = 1; j <= a.length; j++) {
      if (b[i - 1] === a[j - 1]) {
        matrix[i][j] = matrix[i - 1][j - 1];
      } else {
        matrix[i][j] = Math.min(
          matrix[i - 1][j - 1] + 1,
          matrix[i][j - 1] + 1,
          matrix[i - 1][j] + 1
        );
      }
    }
  }

  return matrix[b.length][a.length];
}

// ---------- search ----------
function search(query) {
  if (!query) {
    render(data);
    return;
  }

  const results = data
    .map(item => ({
      item,
      score: scoreItem(item, query)
    }))
    .filter(x => x.score > 0)
    .sort((a, b) => b.score - a.score)
    .map(x => x.item);

  render(results);
}

// ---------- debounce (important for performance) ----------
function debounce(fn, delay) {
  let timer;
  return (...args) => {
    clearTimeout(timer);
    timer = setTimeout(() => fn(...args), delay);
  };
}

const searchInput = document.getElementById("searchInput");

searchInput.addEventListener(
  "input",
  debounce(e => search(e.target.value), 200)
);

// initial render
render(data);
