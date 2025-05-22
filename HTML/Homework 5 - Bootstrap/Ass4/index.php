<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Find Out Your Personality Type</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css" rel="stylesheet">
    <link href="https://fonts.googleapis.com/css2?family=Pacifico&family=DynaPuff:wght@400..700&display=swap" rel="stylesheet">
    <style>
        body {
            font-family: 'DynaPuff', cursive;
        }

        h1,
        h4 {
            font-family: 'Pacifico', cursive;
        }
    </style>
</head>

<body>
    <div class="container mt-5">
        <header class="text-center mb-4">
            <h1>FIND OUT YOUR PERSONALITY TYPE!</h1>
            <h4>Fill in this quick form to find your personality type out</h4>
        </header>

        <form action="ass4.1.html" class="needs-validation" novalidate>
            <div class="mb-3">
                <label for="fname" class="form-label">What is your first name?</label>
                <input type="text" class="form-control" id="fname" name="fname" value="Barack" required>
            </div>
            <div class="mb-3">
                <label for="lname" class="form-label">What is your last name?</label>
                <input type="text" class="form-control" id="lname" name="lname" value="Obama" required>
            </div>
            <div class="mb-3">
                <label for="birthday" class="form-label">Enter your birthday:</label>
                <input type="datetime-local" class="form-control" id="birthday" name="birthday" required>
            </div>
            <div class="mb-3">
                <label for="email" class="form-label">What is your email?</label>
                <input type="email" class="form-control" id="email" name="email" required>
            </div>
            <div class="mb-3">
                <label for="phone" class="form-label">What is your phone number?</label>
                <input type="tel" class="form-control" id="phone" name="phone" placeholder="+370-69331448" pattern="[+]{1}[3]{1}[7]{1}[0]{1}-[6]{1}[0-9]{7}" required>
            </div>
            <div class="mb-3">
                <label for="browser" class="form-label">Choose a browser you use:</label>
                <input list="browsers" name="browser" id="browser" class="form-control" required>
                <datalist id="browsers">
                    <option value="Edge">
                    <option value="Firefox">
                    <option value="Chrome">
                    <option value="Opera">
                    <option value="Safari">
                </datalist>
            </div>
            <p>Choose your interests:</p>
            <div class="mb-3">
                <div class="form-check">
                    <input class="form-check-input" type="radio" id="musical" name="interest" value="Musicals" required>
                    <label class="form-check-label" for="musical">Musicals</label>
                </div>
                <div class="form-check">
                    <input class="form-check-input" type="radio" id="sports" name="interest" value="Sports">
                    <label class="form-check-label" for="sports">Sports</label>
                </div>
                <div class="form-check">
                    <input class="form-check-input" type="radio" id="coding" name="interest" value="Coding">
                    <label class="form-check-label" for="coding">Coding</label>
                </div>
            </div>
            <p>Which of the things below have you done recently:</p>
            <div class="mb-3">
                <div class="form-check">
                    <input class="form-check-input" type="checkbox" id="fashion" name="interest" value="Fashion">
                    <label class="form-check-label" for="fashion">Fashion</label>
                </div>
                <div class="form-check">
                    <input class="form-check-input" type="checkbox" id="cooking" name="interest" value="Cooking">
                    <label class="form-check-label" for="cooking">Cooking</label>
                </div>
                <div class="form-check">
                    <input class="form-check-input" type="checkbox" id="dancing" name="interest" value="dancing">
                    <label class="form-check-label" for="dancing">Dancing</label>
                </div>
            </div>
            <div class="mb-3">
                <label for="range" class="form-label">Rate your love for One direction:</label>
                <input type="range" class="form-range" id="range" name="range" min="0" max="100">
            </div>
            <div class="mb-3">
                <label for="month" class="form-label">Favorite month of the year?</label>
                <input type="month" class="form-control" id="month" name="month">
            </div>
            <div class="mb-3">
                <label for="week" class="form-label">Favorite week of the year?</label>
                <input type="week" class="form-control" id="week" name="week">
            </div>
            <div class="mb-3">
                <label for="number" class="form-label">Pick your favourite number:</label>
                <input type="number" class="form-control" id="number" name="number">
            </div>
            <div class="mb-3">
                <label for="time" class="form-label">Best time for a night out:</label>
                <input type="time" class="form-control" id="time" name="time">
            </div>
            <div class="mb-3">
                <label for="myfile" class="form-label">Upload a selfie:</label>
                <input type="file" class="form-control" id="myfile" name="myfile">
            </div>
            <div class="mb-3">
                <label for="favcolour" class="form-label">Pick your favorite color:</label>
                <input type="color" class="form-control form-control-color" id="favcolour" name="favcolour" value="#ff0000">
            </div>
            <div class="mb-3">
                <label for="URL" class="form-label">Your favorite website:</label>
                <input type="url" class="form-control" id="URL" name="URL">
            </div>
            <div class="mb-3">
                <label for="cars" class="form-label">Choose a preferred car:</label>
                <select class="form-select" id="cars" name="cars">
                    <option value="tesla">Tesla</option>
                    <option value="bmw">BMW</option>
                    <option value="audi">Audi</option>
                    <option value="jeep">Jeep</option>
                </select>
            </div>
            <div class="mb-3">
                <label for="message" class="form-label">Share something about yourself:</label>
                <textarea class="form-control" name="message" id="message" rows="5"></textarea>
            </div>
            <button class="btn btn-primary" type="submit">Submit</button>
        </form>
    </div>

    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/js/bootstrap.bundle.min.js"></script>
</body>

</html>