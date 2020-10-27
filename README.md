# hsu07_humidity_sensor

I salvaged a little HSU-07 sensor from a broken dehumidifier.  Hooked it up to my arduino and read some values from it- it looked to be working fine.

Found the datasheet at http://www.datasheet.hk/download.php?id=1658014&pdfid=6B4C785A9E706B899B73FB7599952FD7&file=0330\hsu-07_2016208.pdf and copied the sparse data values mapping output voltage to relative humidity.

Using an interpolation library I found online, it was pretty simple then to map to a proper value based on what was coming off the sensor.

