var mdiv;
window.onload = function dgs() {
	mdiv = document.getElementById("mdiv");
	var xs = document.getElementsByClassName("graph");
	for (var i = 0; i < xs.length; i++) {
		draw_graph(xs[i].children[0], JSON.parse(xs[i].getAttribute("gdata")));
	}
}

function draw_graph(ele, data) {

	/* find the max and minimum from the data */
	max = min = data.ydata[0];
	for (var i = 0; i < data.ydata.length; i++) {
		var x = data.ydata[i];
		max = (max < x) ? x : max;
		min = (min > x) ? x : min;
	}

	var ht = +ele.offsetHeight;
	var wd = +ele.offsetWidth;
	var dtemp = "", ctemp = "";
	var xoff = 10;
	var yoff = 10;
	var yaspect = (ht - (2 * yoff)) / ((max - min));
	var xaspect = (wd - (2 * xoff)) / (data.ydata.length - 1);
	var yh = yaspect * ht / (data.ydivs - 1);
	var xw = xaspect * wd / (data.xdivs - 1);

	wkv("height", ht);
	wkv("width", wd);
	wkv("xoffset", xoff);
	wkv("yoffset", yoff);
	wkv("max", max);
	wkv("min", min);
	wkv("x-aspect ratio", xaspect);
	wkv("y-aspect ratio", yaspect);
	wkv("grid-y-rowheight", yh);
	wkv("grid-x-colwidth", xw);
	wkv("data", data.ydata);

	data.background = data.background == null ? "#fff" : data.background;
	data.stroke = data.stroke == null ? "#000" : data.stroke;

	var glines = `<line x1="0" y1="${ht}" x2="${wd}" y2="${ht}" style="stroke:gray" /><line x1="0" y1="${ht}" x2="0" y2="0" style="stroke:gray" />`;

	for (var tmp = ht - yh; tmp > 0; tmp -= yh) {
		glines += `<line x1="0" y1="${tmp}" x2="${wd}" y2="${tmp}" style="stroke:lightgray; stroke-width: 1px;"/>`;
	}
	for (var tmp = 0; tmp < wd; tmp += xw) {
		glines += `<line x1="${tmp}" y1="${0}" x2="${tmp}" y2="${ht}" style="stroke:lightgray; stroke-width: 1px;"/>`;
	}

	for (var i = 0; i < data.ydata.length; i++) {
		var x = xoff + (i * xaspect);
		var y = (ht - (yaspect * data.ydata[i]));
		dtemp += x + "," + y + " ";
		ctemp += `<circle cx="${x}" cy="${y}" r="3" stroke="black" stroke-width="2" fill="white" />`;
	}
	ele.innerHTML = `<svg height='${ht}' width='${wd}' style='background: ${data.background};'>${glines}<polyline style='fill:none; stroke:${data.stroke}; stroke-width:2px;' points='${dtemp}'/>${ctemp}</svg>`;
}

function wkv(key, value) {
	mdiv.innerHTML += `<tr><td style="width: 200px;"><b>${key}</b></td><td>${value}</td></tr>`;
}