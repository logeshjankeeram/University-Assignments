<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Bootstrap Flexbox Example</title>
    <link href="https://fonts.googleapis.com/css2?family=Roboto:wght@100;400;700&display=swap" rel="stylesheet">
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css" rel="stylesheet">
    <style>
        body {
            font-family: 'Roboto', sans-serif;
        }

        .container {
            background-color: #f0f0f0;
            padding: 10px;
        }

        .item {
            background-color: #ffffff;
            border: 1px solid #ddd;
            padding: 20px;
            text-align: center;
            margin: 10px;
        }

        .item-1 {
            flex-basis: 100%;
        }

        .item-2,
        .item-3 {
            flex-basis: calc(50% - 20px);
        }

        .item-4,
        .item-5,
        .item-6 {
            flex-basis: calc(33.333% - 20px);
        }

        .item-7 {
            flex-basis: calc(66.666% - 20px);
        }
    </style>
</head>

<body>
    <div class="container d-flex flex-wrap">
        <div class="item item-1">Item 1</div>
        <div class="item item-2">Item 2</div>
        <div class="item item-3">Item 3</div>
        <div class="item item-4">Item 4</div>
        <div class="item item-5">Item 5</div>
        <div class="item item-6">Item 6</div>
        <div class="item item-7">Item 7</div>
    </div>

    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/js/bootstrap.bundle.min.js"></script>
</body>

</html>