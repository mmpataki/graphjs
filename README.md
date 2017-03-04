# mchartjs
A chart library basically built for my mnotes app (it's reusable for webapps too) written in javascript to render charts like bar charts and more.

### How to use
* download the zip file and extract it or try the following commands
```bash
  $: git clone https://github.com/mmpataki/mchartjs
  $: cd mchartjs/
```
* copy the mchartjs.js  and mchartjs.css files to your working directory.
* include these files in your html
```html
  <script src="mchartjs.js"></script>
  <link href="mchartjs.css" rel="stylesheet" type="text/css" >
```


### Now to render charts
* create an `div` element with className 'mchart'.
* create the json object of the chart you want to render(look below for available attributes). stringify it and set the value of `gdata` attribute of the above created div element to this string. Below given is my favorite example.

```html
<div class="mchart" gdata='{"type": "region", "vgrids": true, "hgrids": true, "ydivs": 5, "xdivs": 5, "datasets": [{"fill": "skyblue", "data": [484,529,201,536,136,265,45,578,107,55]}, {"fill": "forestgreen", "data": [45,121,552,316,206,271,389,218,559,450]}]}'>
</div>
```
### Attributes of the chart that you can specify
Name | Meaning | Possible values
-----|---------|-------------------
type | type of the chart | (region\|bar\|dot)
vgrids | do you want to see vertical gridlines | (true\|false)
hgrids | do you want to see horizontal gridlines | (true\|false)
ydivs | number of horizontal gridlines you want | any +ve integer
xdivs | number of vertical gridlines you want | any +ve integer
datasets | the data to be visualised | a JSON array of dataset (refer dataset attributes)

### Dataset attributes
The datasets field of the above JSON formed is array of dataset elements which have the following attributes. Thinking why it's an array? Since you can plot for multiple datasets it's needed.

Name | Meaning | Possible values
-----|---------|-----------------
fill | color to fill in the chart useful only for bar and region charts | any HTML color or rgb color code
stroke | color of the stroke for dot charts | any HTML color or rgb color code
cfill | color to fill in the circle drawn in dot chart | any HTML color or rgb color code
data | data to be plotted | array of integers like [484,529,201]
cradius | radius of the circle drawn in dot chart | any +ve integer value

refer http://learningweb-1996.appspot.com/mchartjs/ for a sample
