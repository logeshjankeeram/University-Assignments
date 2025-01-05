<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Image Gallery</title>
    <!-- Bootstrap CSS -->
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css" rel="stylesheet">
    <style>
        .img-container {
            padding: 0;
        }

        .img-fluid {
            width: 100%;
            height: 160px;
            object-fit: cover;
        }
    </style>
</head>

<body>
    <div class="container">
        <h2 class="text-center mt-3 mb-3">HTML Assignment 2</h2>
        <div class="row g-0">
            <div class="col-4 img-container">
                <img src="image1.jpg" class="img-fluid" alt="Image 1">
            </div>
            <div class="col-4 img-container">
                <img src="image2.jpg" class="img-fluid" alt="Image 2">
            </div>
            <div class="col-4 img-container">
                <img src="image3.jpg" class="img-fluid" alt="Image 3">
            </div>
        </div>
        <div class="row g-0">
            <div class="col-12 img-container">
                <img src="image4.jpg" class="img-fluid" alt="Image 4">
            </div>
        </div>
        <div class="row g-0">
            <div class="col-6 img-container">
                <img src="image5.jpg" class="img-fluid" alt="Image 5">
            </div>
            <div class="col-6 img-container">
                <img src="image6.jpg" class="img-fluid" alt="Image 6">
            </div>
        </div>
    </div>



</body>

</html>