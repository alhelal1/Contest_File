(function(e){function n(r){if(t[r])return t[r].exports;var i=t[r]={exports:{},id:r,loaded:!1};return e[r].call(i.exports,i,i.exports,n),i.loaded=!0,i.exports}var t={};return n.m=e,n.c=t,n.p="",n(0)})([function(e,t,n){var r,i,s,o,u,a,f;i=n(3),f=n(17),o=n(23),r=n(24),u=n(25),a=n(28),s=n(21),window.template=function(){var e,t,n,l,c,h,p,d,v,m,g,y,b,w,E,S;return S=req.w,n=req.h,t=req.ctype,p=req.qid,e=req.ad,h=req.ls,c=s.setUrl(e[0])+"&ls="+h+"&ctype="+t,a.checkTestLs(h)&&parseInt(S)===300&&parseInt(n)===250?u.main():(conf.linkAnimation=(d=conf.linkAnimation)!=null?d:!0,f.init(t,p,e,h),JSON.parse(conf.linkAnimation)&&o.init(3e3),E={conWidth:S,conHeight:n,logoSrc:c,bgColor:(v=conf.bgColor)!=null?v:"E5F9DD",hColor:(m=conf.hColor)!=null?m:"72C84B",fsSize:(g=conf.fsSize)!=null?g:14,fsColor:(y=conf.fsColor)!=null?y:"34AB03",fsFamily:(b=conf.fsFamily)!=null?b:"\u5b8b\u4f53"},l=i.getLayout(S,n),w={layout:l,ads:e,setting:E},r(w))}},,,function(e,t){var n;n={getLayout:function(e,t){var n,r,i,s,o,u,a;r=1024>=e&&e>=103&&1024>=t&&t>=28,a=e+"_"+t;switch(a){case"300_250":case"250_250":case"336_280":i={column:2,line:6};break;case"160_600":i={column:1,line:15};break;case"640_60":i={column:6,line:2};break;case"960_90":i={column:9,line:3};break;default:n=Math.floor(e/103),s=Math.floor(t/28),n*s>50&&(s=Math.floor(50/n)),i={column:n,line:s}}return o=u=4,i.itemWidth=Math.floor((e-o*(i.column-1))/i.column),i.itemHeight=Math.floor((t-u*(i.line-1))/i.line),i.spaceX=Math.floor((e-i.column*i.itemWidth)/(i.column-1)),i.spaceY=Math.floor((t-i.line*i.itemHeight)/(i.line-1)),r||(i.column=i.line=0),Number.isNaN(i.itemWidth)&&(i.itemWidth=0),Number.isNaN(i.itemHeight)&&(i.itemHeight=0),Number.isNaN(i.spaceX)&&(i.spaceX=0),Number.isNaN(i.spaceY)&&(i.spaceY=0),i}},e.exports=n},,,,,,,,,,,,,,function(e,t){var n;n={init:function(e,t,n,r){return this.pvSrc="http://stat.lianmeng.360.cn/s2/srp.gif?lm_extend=ctype:"+e+"&qid="+t+"&nu="+n.length+"&ls="+r+"&_r="+(new Date).getTime(),this.clkSrc="http://stat.lianmeng.360.cn/s2/clk.gif?lm_extend=ctype:"+e+"&qid="+t+"&nu="+n.length+"&ls="+r+"&_r="+(new Date).getTime(),this.sendLog(this.pvSrc),$(document).ready(function(e){return function(){return $(document).delegate("a.clk","click",function(t){var n,r,i,s,o,u;return s=$(t.currentTarget),n=(r=s.attr("data-index"))!=null?r:"",o=(i=s.attr("title"))!=null?i:"",u=e.clkSrc+"&index="+n+"&txt="+encodeURIComponent(o)+"&_r="+(new Date).getTime(),e.sendLog(u)})}}(this))},sendLog:function(e){var t;return t=new Image,t.onload=t.onerror=function(){return t=null},t.src=e}},e.exports=n},,function(e,t,n){"use strict";function r(e){return e!=null&&e!==""}function i(e){return(Array.isArray(e)?e.map(i):e&&typeof e=="object"?Object.keys(e).filter(function(t){return e[t]}):[e]).filter(r).join(" ")}function u(e){return s[e]||e}function a(e){var t=String(e).replace(o,u);return t===""+e?e:t}t.merge=function f(e,t){if(arguments.length===1){var n=e[0];for(var i=1;i<e.length;i++)n=f(n,e[i]);return n}var s=e["class"],o=t["class"];if(s||o)s=s||[],o=o||[],Array.isArray(s)||(s=[s]),Array.isArray(o)||(o=[o]),e["class"]=s.concat(o).filter(r);for(var u in t)u!="class"&&(e[u]=t[u]);return e},t.joinClasses=i,t.cls=function(n,r){var s=[];for(var o=0;o<n.length;o++)r&&r[o]?s.push(t.escape(i([n[o]]))):s.push(i(n[o]));var u=i(s);return u.length?' class="'+u+'"':""},t.style=function(e){return e&&typeof e=="object"?Object.keys(e).map(function(t){return t+":"+e[t]}).join(";"):e},t.attr=function(n,r,i,s){return n==="style"&&(r=t.style(r)),"boolean"==typeof r||null==r?r?" "+(s?n:n+'="'+n+'"'):"":0==n.indexOf("data")&&"string"!=typeof r?(JSON.stringify(r).indexOf("&")!==-1&&console.warn("Since Jade 2.0.0, ampersands (`&`) in data attributes will be escaped to `&amp;`"),r&&typeof r.toISOString=="function"&&console.warn("Jade will eliminate the double quotes around dates in ISO form after 2.0.0")," "+n+"='"+JSON.stringify(r).replace(/'/g,"&apos;")+"'"):i?(r&&typeof r.toISOString=="function"&&console.warn("Jade will stringify dates in ISO form after 2.0.0")," "+n+'="'+t.escape(r)+'"'):(r&&typeof r.toISOString=="function"&&console.warn("Jade will stringify dates in ISO form after 2.0.0")," "+n+'="'+r+'"')},t.attrs=function(n,r){var s=[],o=Object.keys(n);if(o.length)for(var u=0;u<o.length;++u){var a=o[u],f=n[a];"class"==a?(f=i(f))&&s.push(" "+a+'="'+f+'"'):s.push(t.attr(a,f,!1,r))}return s.join("")};var s={"&":"&amp;","<":"&lt;",">":"&gt;",'"':"&quot;"},o=/[&<>"]/g;t.escape=a,t.rethrow=function l(e,t,r,i){if(e instanceof Error){if((typeof window!="undefined"||!t)&&!i)throw e.message+=" on line "+r,e;try{i=i||n(20).readFileSync(t,"utf8")}catch(s){l(e,null,r)}var o=3,u=i.split("\n"),a=Math.max(r-o,0),f=Math.min(u.length,r+o),o=u.slice(a,f).map(function(e,t){var n=t+a+1;return(n==r?"  > ":"    ")+n+"| "+e}).join("\n");throw e.path=t,e.message=(t||"Jade")+":"+r+"\n"+o+"\n\n"+e.message,e}throw e},t.DebugItem=function(t,n){this.lineno=t,this.filename=n}},function(e,t){},function(e,t){var n;n={serialize:function(e){var t,n,r,i,s,o;i=[],r=function(e){return i.push(e.name+"="+e.val)};for(t=n=0,o=e.length;0<=o?n<o:n>o;t=0<=o?++n:--n)r(e[t]);return s=i.join("&"),s},setUrl:function(e){var t,n,r,i;return n=[],t=e.curl.substr(0,e.curl.search(/\?/)+1),r=e.curl.substr(e.curl.search(/\?/)+1),r.replace(/([^=&]+)=([^&]*)/g,function(e,t,r){return t==="q"?n.push({name:t,val:"360"}):n.push({name:t,val:r})}),t?i=t+this.serialize(n):i=e.curl,i}},e.exports=n},,function(e,t){var n;n={init:function(e,t){return t==null&&(t=3),this.index=0,this.length=t,$(document).ready(function(t){return function(){var n,r;r=0;while(r<t.length)$("#container").find("a.clk").eq(r).length>0&&(n=$("#container").find("a.clk").eq(r).find("div").eq(0),r===0&&n.addClass("select"),t.getStrLen(n.html())<10&&n.append('<span class="triangle"></span>')),r++;return t.run(),setInterval(function(){return t.run()},e)}}(this))},run:function(){var e,t;this.index=this.index%this.length,e=0;while(e<this.length)$("#container").find("a.clk").eq(e).length>0&&(t=$("#container").find("a.clk").eq(e).find("div").eq(0),e===this.index?t.removeClass("highlight").addClass("select"):t.removeClass("select").addClass("highlight")),e++;return this.index++},getStrLen:function(e){var t,n,r;r=0,n=0;while(n<e.length)t=e.charCodeAt(n),t>=1&&t<=126||65376<=t&&t<=65439?r++:r+=2,n++;return r}},e.exports=n},function(e,t,n){var r=n(19);e.exports=function(t){var n=[],i={},s,o=t||{};return function(e,t,i){n.push("<style>html{\n    width: "+r.escape((s=i.conWidth)==null?"":s)+"px;\n    height: "+r.escape((s=i.conHeight)==null?"":s)+"px;\n}\nhtml,body,div,a{\n    margin : 0;\n    padding : 0;\n    border : 0;\n    outline : 0;\n    font-size: 100%;\n    font-family: Microsoft Yahei, '\u5b8b\u4f53';\n}    \nbody{\n    background-color: white;\n}    \na{\n    text-decoration: none;    \n}    \n.container{\n    width: "+r.escape((s=i.conWidth)==null?"":s)+"px;\n    height: "+r.escape((s=i.conHeight)==null?"":s)+"px;\n}    \n.logo{\n    position:absolute;    \n    right:0;\n    bottom:0;\n    width: 18px;\n    height: 18px;\n    background:url('http://p5.qhimg.com/d/inn/3ac333ef/logo2.png') no-repeat;\n    _filter:progid:DXImageTransform.Microsoft.AlphaImageLoader(src=\"http://p5.qhimg.com/d/inn/3ac333ef/logo2.png\");\n    _background:none;\n}\n.row::after{\n    clear: both;    \n}\n.item{\n    float: left;\n    background-color: #"+r.escape((s=i.bgColor)==null?"":s)+";\n    text-align: center;\n    cursor: pointer;\n    position: relative;\n    overflow: hidden;\n}\n.highlight{\n    background-color: #"+r.escape((s=i.hColor)==null?"":s)+";  \n    color: white;\n    width : "+r.escape((s=t.itemWidth)==null?"":s)+"px!important;\n    height : "+r.escape((s=t.itemHeight)==null?"":s)+"px!important;\n    line-height: "+r.escape((s=t.itemHeight)==null?"":s)+"px!important;\n}\n.select{\n    border: 2px solid #"+r.escape((s=i.hColor)==null?"":s)+";\n    width : "+r.escape((s=t.itemWidth-4)==null?"":s)+"px!important;\n    height : "+r.escape((s=t.itemHeight-4)==null?"":s)+"px!important;\n    line-height: "+r.escape((s=t.itemHeight-4)==null?"":s)+"px!important;\n}\n.select .triangle{\n    border-color: transparent transparent transparent #"+r.escape((s=i.hColor)==null?"":s)+";\n}\n.row{\n    height : "+r.escape((s=t.itemHeight)==null?"":s)+"px;\n    line-height: "+r.escape((s=t.itemHeight)==null?"":s)+"px;\n}\n.row a{\n    font-size: "+r.escape((s=i.fsSize)==null?"":s)+'px;\n    font-family: "'+r.escape((s=i.fsFamily)==null?"":s)+'","\u5b8b\u4f53";\n    color: #'+r.escape((s=i.fsColor)==null?"":s)+";\n}\n.row a .item{\n    width : "+r.escape((s=t.itemWidth)==null?"":s)+"px;\n    height : "+r.escape((s=t.itemHeight)==null?"":s)+"px;\n    line-height: "+r.escape((s=t.itemHeight)==null?"":s)+"px;\n}\n.row .spaceX{\n    height : "+r.escape((s=t.itemHeight)==null?"":s)+"px;\n    line-height: "+r.escape((s=t.itemHeight)==null?"":s)+"px;\n    float: left;\n}\n.container .spaceY{\n    width: "+r.escape((s=i.conWidth)==null?"":s)+'px;    \n}\n.triangle {\n    width: 0;\n    height: 0;\n    display: block;\n    zoom: 1;\n    position: absolute;\n    top: 50%;\n    right: 0;\n    margin-top: -4px;\n    border-width: 5px;\n    overflow: hidden;\n    font-size: 0;\n    line-height: 0;\n    border-style: dashed dashed dashed solid;\n    border-color: transparent transparent transparent #fff;\n}\n\n\n</style><div id="container">');var o=0,u=0;while(o<t.line){n.push('<div class="row">'),u=0;while(u<t.column){var a=o*t.column+u;n.push("<a"+r.attr("href",""+e[a].curl+"",!0,!1)+' target="_blank"'+r.attr("title",""+e[a].tit+"",!0,!1)+r.attr("data-index",""+a+"",!0,!1)+' class="clk"><div class="item">'+r.escape(null==(s=e[a].tit)?"":s)+"</div></a>"),u!=t.column-1&&n.push("<div"+r.attr("style","width:"+t.spaceX+"px;",!0,!1)+' class="spaceX"></div>'),u++}n.push("</div><div"+r.attr("style","height:"+t.spaceY+"px;",!0,!1)+' class="spaceY"></div>'),o++}n.push("</div><a"+r.attr("href",""+i.logoSrc+"",!0,!1)+' target="_blank" data-t="logo"><div class="logo"></div></a>')}.call(this,"ads"in o?o.ads:typeof ads!="undefined"?ads:undefined,"layout"in o?o.layout:typeof layout!="undefined"?layout:undefined,"setting"in o?o.setting:typeof setting!="undefined"?setting:undefined),n.join("")}},function(e,t,n){var r,i,s,o,u;r=n(26),o=n(27),u=n(17),i=n(21),s={main:function(){var e,t,n,s,a,f,l,c,h,p;return p=req.w,n=req.h,t=req.ctype,l=req.qid,e=req.ad,a=req.ls,u.init(t,l,e,a),s=i.setUrl(e[0])+"&ls="+a+"&ctype="+t,h={conWidth:p,conHeight:n,logoSrc:s,bgColor:"FFFFFF",hColor:"abb4b9",fsSize:14,fsColor:"333333",fsFamily:"\u5b8b\u4f53"},f=r.getLayout(e,h.fsSize),c={ads:f,setting:h},o(c)}},e.exports=s},function(e,t){var n;n={getStrlen:function(e){var t,n;return t=e.replace(/[\u4e00-\u9fa5\u3002\u2022]+/g,""),n=(2*e.length-t.length)/2,n},setAd:function(e,t,n,r){return e[t].index=t,e[t].width=this.getStrlen(e[t].tit)*n+r,e[t].height=33},setArrayAd:function(e,t,n,r,i){var s,o,u;for(s=o=0,u=n;0<=u?o<u:o>u;s=0<=u?++o:--o)this.setAd(e,t+s,r,i);return e},getLayout:function(e,t){var n,r,i,s,o,u,a,f,l,c,h,p,d,v,m,g,y,b,w;h=6,d=2,n=40,c=e.length,i=0,o=0,m=[],s=[],v=2,r=0;while(i<h){if(i<2)e[o].width=300,e[o].height=54,e[o].index=o,s.push(e[o]),o++;else{o+2<c?w=(this.getStrlen(e[o].tit)+this.getStrlen(e[o+1].tit)+this.getStrlen(e[o+2].tit))*t+2*d+n*3:w=(this.getStrlen(e[o].tit)+this.getStrlen(e[o+1].tit))*t+1*d+n*2;if(r===v||w>300){w=(this.getStrlen(e[o].tit)+this.getStrlen(e[o+1].tit))*t+n*2,b=Math.floor((300-w-d)/2)+n,this.setArrayAd(e,o,2,t,b),e[o+1].width=300-e[o].width-d,g=[0,1];for(a=0,f=g.length;a<f;a++)u=g[a],s.push(e[o+u]);o+=2}else{r++,b=Math.floor((300-w-2*d)/3)+n,this.setArrayAd(e,o,3,t,b),e[o+2].width=300-e[o].width-e[o+1].width-2*d,y=[0,1,2];for(p=0,l=y.length;p<l;p++)u=y[p],s.push(e[o+u]);o+=3}}m.push(s),s=[],i++}return m}},e.exports=n},function(e,t,n){var r=n(19);e.exports=function(t){var n=[],i={},s,o=t||{};return function(e,t){n.push("<style>html{\n    width: "+r.escape((s=t.conWidth)==null?"":s)+"px;\n    height: "+r.escape((s=t.conHeight)==null?"":s)+'px;\n}\nhtml,body,div,a{\n    margin : 0;\n    padding : 0;\n    border : 0;\n    outline : 0;\n    font-size: 100%;\n    font-family: "'+r.escape((s=t.fsFamily)==null?"":s)+'",Microsoft Yahei,"\u5b8b\u4f53";\n}    \nbody{\n    background-color: white;\n}    \na{\n    text-decoration: none;    \n}    \n#container{\n    width: '+r.escape((s=t.conWidth)==null?"":s)+"px;\n    height: "+r.escape((s=t.conHeight)==null?"":s)+"px;\n}    \n.logo{\n    position:absolute;    \n    right:0;\n    bottom:0;\n    width: 18px;\n    height: 18px;\n    background:url('http://p5.qhimg.com/d/inn/3ac333ef/logo2.png') no-repeat;\n    _filter:progid:DXImageTransform.Microsoft.AlphaImageLoader(src=\"http://p5.qhimg.com/d/inn/3ac333ef/logo2.png\");\n    _background:none;\n}\n.row::after{\n    clear: both;    \n}\n.item{\n    float: left;\n    background-color: #"+r.escape((s=t.bgColor)==null?"":s)+";\n    text-align: center;\n    cursor: pointer;\n    position: relative;\n    overflow: hidden;\n    border: 1px solid #cfd8dc;\n    padding: 1px;\n}\n.row a{\n    font-size: "+r.escape((s=t.fsSize)==null?"":s)+'px;\n    font-family: "'+r.escape((s=t.fsFamily)==null?"":s)+'","\u5b8b\u4f53";\n    color: #'+r.escape((s=t.fsColor)==null?"":s)+";\n}\n.row a:hover{\n    font-weight: bold;\n}\n.row a:hover .item{\n    padding: 0;\n    border: 2px solid #"+r.escape((s=t.hColor)==null?"":s)+";\n}\n.row .spaceX{\n    width: 2px;    \n    height : 33px;\n    line-height: 33px;\n    float: left;\n}\n#container .spaceY{\n    width: 300px;\n    height: 2px;\n    line-height: 2px;\n    float: left;\n}\n#container .bigFont{\n    font-size: 20px;\n}\n</style>"),i.colLayout=s=function(t){var i=this&&this.block,o=this&&this.attributes||{},u=0;while(u<e[t].length)n.push("<a"+r.attr("href",e[t][u].curl,!0,!1)+' target="_blank"'+r.attr("title",e[t][u].tit,!0,!1)+r.attr("data-index",e[t][u].index,!0,!1)+r.cls(["clk",e[t].length==1?"bigFont":""],[null,!0])+"><div"+r.attr("style","width:"+(e[t][u].width-4)+"px;height:"+(e[t][u].height-4)+"px;line-height:"+(e[t][u].height-4)+"px",!0,!1)+' class="item">'+r.escape(null==(s=e[t][u].tit)?"":s)+"</div></a>"),u!=e[t].length-1&&n.push('<div class="spaceX"></div>'),u++},n.push('<div id="container">');var o=0;while(o<e.length)n.push('<div class="row">'),i.colLayout(o),n.push("</div>"),o!=e.length-1&&n.push('<div class="spaceY"></div>'),o++;n.push("</div><a"+r.attr("href",""+t.logoSrc+"",!0,!1)+' target="_blank" data-t="logo"><div class="logo"></div></a>')}.call(this,"ads"in o?o.ads:typeof ads!="undefined"?ads:undefined,"setting"in o?o.setting:typeof setting!="undefined"?setting:undefined),n.join("")}},function(e,t){var n;n={testLs:["s75b9aa9d88","s3be1b5b782","s1036ce4178","s00dfdc2b87","s5367c6397e"],checkTestLs:function(e){var t;return t=this.testLs.filter(function(t){if(t===e)return!0}),t.length?!0:!1}},e.exports=n}]);