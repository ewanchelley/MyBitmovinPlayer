//
//  ContentView.swift
//  MyBitmovinPlayer
//
//  Created by Ewan Chelley on 18/12/2024.
//

import SwiftUI
import Combine
import BitmovinPlayer

let streamURLParkour = "https://bitmovin-a.akamaihd.net/content/MI201109210084_1/m3u8s/f08e80da-bf1d-4e3d-8899-f0f6155f6efa.m3u8"
let posterURLParkour = "https://bitmovin-a.akamaihd.net/content/MI201109210084_1/poster.jpg"

let streamURLBBC = "https://vs-hls-push-uk-live.akamaized.net/x=4/i=urn:bbc:pips:service:bbc_one_london/mobile_wifi_main_sd_abr_v2.m3u8"
let posterURLBBC = "https://ichef.bbci.co.uk/images/ic/1008x567/p0bvs64x.jpg"


struct ContentView: View {
    private let player: Player
    @State var isLive = true
    
    init() {
        player = createPlayer()
    }
    
    @State var quality: String = "?"
    
    var body: some View {
        ZStack {
            VStack {
                HStack{
                    Button(action: loadBBCSource  ) {
                        Text("BBC One")
                    }
                    .buttonStyle(.borderedProminent)
                    Button(action: loadParkourSource) {
                        Text("Parkour")
                    }
                    .buttonStyle(.borderedProminent)
                }
                .padding()
                HStack{
                    if !isLive {
                        Button(action: { player.seek(time: 0) } ) {
                            Image(systemName: "backward.end.alt.fill")
                        }
                    }
                    
                    Button(action: playOrPause) {
                        Image(systemName: "playpause.fill")
                    }
                    if isLive {
                        Button(action: { player.timeShift = 0 } ) {
                            Image(systemName: "forward.end.alt.fill")
                        }
                    }
                    
                }
                .padding()
                
                
                VideoPlayerView(
                    player: player
                )
                .onReceive(player.events.on(PlayerEvent.self)) { (event: PlayerEvent) in
                    dump(event, name: "[Player Event]", maxDepth: 1)
                    
                }
                .onReceive(player.events.on(SourceEvent.self)) { (event: SourceEvent) in
                    dump(event, name: "[Source Event]", maxDepth: 1)
                }
                .frame(height: 400)
                
                
            }
            .padding()
            
            if !isLive {
                HStack {
                    Button("-10") {
                        print("Seeked -10 Seconds!")
                        player.seek(time: player.currentTime - 10)
                    }
                    .buttonStyle(.bordered)
                    .tint(.orange)
                    
                    Button("+10") {
                        print("Seeked +10 Seconds!")
                        player.seek(time: player.currentTime + 10)
                    }
                    .buttonStyle(.bordered)
                    .tint(.green)
                }
            }
        }
    }


    func playOrPause() {
        if player.isPlaying {
            player.pause()
        } else {
            player.play()
        }
    }
    
    func loadBBCSource() {
        player.load(source: createSourceBBC())
        isLive = true
    }
    
    func loadParkourSource() {
        player.load(source: createSourceParkour())
        isLive = false
    }
    
}

func createPlayer() -> Player {
    let player = PlayerFactory
        .createPlayer(playerConfig: createPlayerConfig())
    player.load(source: createSourceBBC())
    return player
}

func createPlayerConfig() -> PlayerConfig {
    let playerConfig = PlayerConfig()
    playerConfig.styleConfig.userInterfaceType = .bitmovin
    
    let uiConfig = BitmovinUserInterfaceConfig()
    uiConfig.customOptions = [
        "metadata": [
            "markers": [
                [
                  "time": 24,
                  "title": "Salto on the edge"
                ],
                [
                  "time": 69,
                  "title": "Interview - Marcus Gustafsson"
                ],
                [
                  "time": 105,
                  "title": "Parcour rating explained"
                ],
                [
                  "time": 188,
                  "duration": 11,
                  "title": "And we have a winner!"
                ]
            ]
        ]
    ]
    playerConfig.styleConfig.userInterfaceConfig = uiConfig
    return playerConfig
}



func createSourceBBC() -> Source {
    guard let streamUrl = URL(string: streamURLBBC),
         let posterUrl = URL(string: posterURLBBC) else {
       fatalError("Invalid URL")
    }
    let sourceConfig = SourceConfig(url: streamUrl, type: .hls)
    sourceConfig.posterSource = posterUrl
    sourceConfig.title = "BBC One"
    sourceConfig.sourceDescription = "This is Live BBC One."
    
    return SourceFactory.createSource(from: sourceConfig)
}

func createSourceParkour() -> Source {
    guard let streamUrl = URL(string: streamURLParkour),
          let posterUrl = URL(string: posterURLParkour) else {
       fatalError("Invalid URL")
    }
    let sourceConfig = SourceConfig(url: streamUrl, type: .hls)
    sourceConfig.posterSource = posterUrl
    sourceConfig.title = "Parkour"
    sourceConfig.sourceDescription = "This is a Parkour video."
    
    return SourceFactory.createSource(from: sourceConfig)
}




#Preview {
    ContentView()
}
