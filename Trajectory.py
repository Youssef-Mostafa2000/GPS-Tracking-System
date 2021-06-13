import gmplot

Longitude_string = ["70.8701919","78.048457","78.0413095"]
Latitude_string = ["30.3358376","30.307977","30.3216419"]
# Pass the absolute path

#converting string to float
Latitude = []
for item in Latitude_string:
    Latitude.append(float(item))
Longitude = []
for item in Longitude_string:
    Longitude.append(float(item))

#Latitude = [ 30.142505, 30.142503, 30.142499, 30.142497 ]
#Longitude = [ 31.397334, 31.497332, 31.397329, 31.397327 ]
  
google_map = gmplot.GoogleMapPlotter(30.142503,31.397332, 13)
  
# scatter method of map object 
# scatter points on the google map

google_map.scatter( Latitude, Longitude, '#FF0000',size = 1, marker = False )

# Plot method Draw a line in
# between given coordinates

google_map.plot(Latitude, Longitude, 'cornflowerblue', edge_width = 2.5)

#google_map.apikey = "AIzaSyAIPPUQ0PSWMjTsgvIWRRcJv3LGfRzGmnA"

google_map.draw( "C:\\Users\\Youssef Mostafa\\Desktop\\map1.html" )

