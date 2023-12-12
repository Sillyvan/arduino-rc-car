<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>Arduino RC</title>
    <script src="main.js"></script>
    <link rel="stylesheet" type="text/css" href="main.css" />
  </head>
  <body>
    <div class="parent">
      <div class="div1">
        <img
        class='button'
          src="imgs/arrow.png" 
          alt="button" class="button" 
          onmousedown="javascript:arduinoComs.holdDown('forward')"
          onmouseup="javascript:arduinoComs.reset()"
        />
      </div>
      <div class="div2">
        <img
          src="imgs/arrow.png"
          alt="button"
          class="button"
          style="transform: rotate(90deg);"
          galleryimg="no"
          onmousedown="javascript:arduinoComs.holdDown('right')"
          onmouseup="javascript:arduinoComs.reset()"
        />
      </div>
      <div class="div3">
        <img
          src="imgs/arrow.png"
          alt="button"
          class="button"
          style="transform: rotate(180deg);"
          onmousedown="javascript:arduinoComs.holdDown('backwards')"
          onmouseup="javascript:arduinoComs.reset()"        />
      </div>
      <div class="div4">
        <img
          src="imgs/arrow.png"
          alt="button"
          class="button"
          style="transform: rotate(270deg);"
          onmousedown="javascript:arduinoComs.holdDown('left')"
          onmouseup="javascript:arduinoComs.reset()"        />
      </div>
    </div>
  </body>
</html>
