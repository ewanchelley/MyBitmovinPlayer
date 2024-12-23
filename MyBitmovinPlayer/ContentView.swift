//
//  ContentView.swift
//  MyBitmovinPlayer
//
//  Created by Ewan Chelley on 18/12/2024.
//

import SwiftUI
import Combine
import BitmovinPlayer


struct ContentView: View {
    private let playerConfig: PlayerConfig
    
    init() {
        playerConfig = PlayerConfig()
        // Bitmovin UI
        playerConfig.styleConfig.userInterfaceType = .bitmovin
        // "System" UI, with -10/+10 second seeks.
//        playerConfig.styleConfig.userInterfaceType = .system
        
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
        
    }
    
    var body: some View {
        ZStack {
            let player = bmPlayer()
            VideoPlayerView(
                player: player
            )
            .onReceive(player.events.on(PlayerEvent.self)) { (event: PlayerEvent) in
                dump(event, name: "[Player Event]", maxDepth: 1)
            }
            .onReceive(player.events.on(SourceEvent.self)) { (event: SourceEvent) in
                dump(event, name: "[Source Event]", maxDepth: 1)
            }
            
            // Add our own UI to do things in the player.
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
        .padding()
    }
    
    func bmPlayer() -> Player {
        let player = PlayerFactory.createPlayer(playerConfig: playerConfig)
        
        guard let streamUrl = URL(string: "https://bitmovin-a.akamaihd.net/content/MI201109210084_1/m3u8s/f08e80da-bf1d-4e3d-8899-f0f6155f6efa.m3u8"),
                     let posterUrl = URL(string: "https://bitmovin-a.akamaihd.net/content/MI201109210084_1/poster.jpg") else {
                   fatalError("Invalid URL")
               }
        
        let sourceConfig = SourceConfig(url: streamUrl, type: .hls)
        sourceConfig.posterSource = posterUrl
        sourceConfig.title = "This Is A Title!"
        sourceConfig.sourceDescription = "This is a source description of This Is A Title."
        
        let source = SourceFactory.createSource(from: sourceConfig)
        
        player.load(source: source)
        
        return player
    }
}



#Preview {
    ContentView()
}
