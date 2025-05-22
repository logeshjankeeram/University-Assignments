<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <style>
        table {
            /* in here we can  put the styling for the table*/
            text-align: center;
            /* this will align the text/content inside each cell to the centre*/
            border-collapse: collapse;
            /* as it says it collapses the border so no double lines*/
            border: none;
            /* table will have no visible borders*/
            margin: auto;
            /* evenly distributes space on both sides of the table*/
            border-spacing: 0
        }

        td {
            border: none;
            padding: 0;
            font-size: 0;
            line-height: 0;
            text-align: center;
        }
    </style>
</head>

<body>
    <h2>HTML Assignment</h2>
    <table>
        <tr>
            <td colspan="2"><img src="image1.jpg" style="width:150px;height:160px;"></td>
            <td colspan="2"><img src="image2.jpg" style="width:150px;height:160px;"></td>
            <td colspan="2"><img src="image3.jpg" style="width:150px;height:160px;"></td>
        </tr>
        <tr>
            <td colspan="6"><img src="image4.jpg" style="width:450px;height:160px;"></td>
        </tr>
        <tr>
            <td colspan="3"><img src="image5.jpg" style="width:225px;height:160px;"></td>
            <td colspan="3"><img src="image6.jpg" style="width:225px;height:160px;"></td>
            <td></td>
        </tr>
    </table>
</body>

</html>