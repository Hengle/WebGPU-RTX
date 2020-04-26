open WebGPU;

let buildScene = state => {
  let (light1, state) = GameObject.create(state);

  let (directionLight1, state) = DirectionLight.create(state);
  let state =
    state
    |> DirectionLight.setIntensity(directionLight1, 1.)
    |> DirectionLight.setPosition(directionLight1, (0., 1., 1.));

  let state = state |> GameObject.addDirectionLight(light1, directionLight1);

  let (light2, state) = GameObject.create(state);

  let (directionLight2, state) = DirectionLight.create(state);
  let state =
    state
    |> DirectionLight.setIntensity(directionLight2, 0.5)
    |> DirectionLight.setPosition(directionLight2, (1., 2., 1.));

  let state = state |> GameObject.addDirectionLight(light2, directionLight2);

  let (camera1, state) = GameObject.create(state);

  let (cameraView1, state) = CameraView.create(state);
  let state = state |> CameraView.setCurrentCameraView(cameraView1);

  let (arcballCameraController1, state) =
    ArcballCameraController.create(state);
  let state =
    state
    |> ArcballCameraController.setCurrentArcballCameraController(
         arcballCameraController1,
       )
    |> ArcballCameraController.setPhi(
         arcballCameraController1,
         Js.Math._PI /. 2.,
       )
    |> ArcballCameraController.setTheta(
         arcballCameraController1,
         Js.Math._PI /. 2.,
       )
    |> ArcballCameraController.setTarget(
         arcballCameraController1,
         (0., 0., 0.),
       )
    |> ArcballCameraController.setRotateSpeed(arcballCameraController1, 1.)
    |> ArcballCameraController.setWheelSpeed(arcballCameraController1, 1.)
    |> ArcballCameraController.setDistance(arcballCameraController1, 20.);

  let state =
    state
    |> GameObject.addCameraView(camera1, cameraView1)
    |> GameObject.addArcballCameraController(
         camera1,
         arcballCameraController1,
       );

  let (triangle1, state) = GameObject.create(state);

  let (tran1, state) = Transform.create(state);
  let state =
    state
    // |> Transform.setTranslation(tran1, (0., (-5.), 0.))
    |> Transform.setTranslation(tran1, (0., 0., 0.))
    // |> Transform.setRotation(tran1, (30., 45., 0.))
    |> Transform.setRotation(tran1, (0., 20., 0.))
    |> Transform.setScale(tran1, (1., 1., 1.));

  let (geo1, state) = Geometry.create(state);
  let state =
    state
    |> Geometry.setVertexData(geo1, Geometry.buildTriangleVertexData())
    |> Geometry.setIndexData(geo1, Geometry.buildTriangleIndexData());

  let (mat1, state) = PhongMaterial.create(state);
  let state =
    state
    // |> PhongMaterial.setAmbient(mat1, (0.1, 0.1, 0.1))
    |> PhongMaterial.setDiffuse(mat1, (1.0, 0., 0.))
    // |> PhongMaterial.setSpecular(mat1, (0.2, 0.0, 1.0))
    |> PhongMaterial.setShininess(mat1, 36.);
  // |> PhongMaterial.setIllum(mat1, 2)
  // |> PhongMaterial.setDissolve(mat1, 1.);

  let (shader1, state) = Shader.create(state);
  let state = state |> Shader.setHitGroupIndex(shader1, 0);

  let (transformAnim1, state) = TransformAnimation.create(state);
  let state =
    state |> TransformAnimation.setDynamicTransform(transformAnim1, 0);

  let state =
    state
    |> GameObject.addTransform(triangle1, tran1)
    |> GameObject.addGeometry(triangle1, geo1)
    |> GameObject.addPhongMaterial(triangle1, mat1)
    |> GameObject.addShader(triangle1, shader1)
    |> GameObject.addTransformAnimation(triangle1, transformAnim1);

  let (triangle2, state) = GameObject.create(state);

  let (tran2, state) = Transform.create(state);
  let state =
    state
    |> Transform.setTranslation(tran2, (3., 0., 5.))
    |> Transform.setRotation(tran2, (0., 70., 0.))
    |> Transform.setScale(tran2, (5., 5., 5.));

  let (geo2, state) = Geometry.create(state);
  let state =
    state
    |> Geometry.setVertexData(geo2, Geometry.buildTriangleVertexData())
    |> Geometry.setIndexData(geo2, Geometry.buildTriangleIndexData());

  let (mat2, state) = PhongMaterial.create(state);
  let state =
    state
    |> PhongMaterial.setDiffuse(mat2, (0.0, 1., 0.))
    |> PhongMaterial.setShininess(mat2, 36.);

  let (shader2, state) = Shader.create(state);
  let state = state |> Shader.setHitGroupIndex(shader2, 0);

  // let (transformAnim2, state) = TransformAnimation.create(state);
  // let state =
  //   state |> TransformAnimation.setDynamicTransform(transformAnim2, 0);

  let state =
    state
    |> GameObject.addTransform(triangle2, tran2)
    |> GameObject.addGeometry(triangle2, geo2)
    |> GameObject.addPhongMaterial(triangle2, mat2)
    |> GameObject.addShader(triangle2, shader2);
  // |> GameObject.addTransformAnimation(triangle2, transformAnim2);

  let (plane1, state) = GameObject.create(state);

  let (tran2, state) = Transform.create(state);
  let state =
    state
    |> Transform.setTranslation(tran2, (0., (-10.), (-5.)))
    |> Transform.setRotation(tran2, (0., 0., 0.))
    |> Transform.setScale(tran2, (50., 50., 50.));

  let (geo2, state) = Geometry.create(state);
  let state =
    state
    |> Geometry.setVertexData(geo2, Geometry.buildPlaneVertexData())
    |> Geometry.setIndexData(geo2, Geometry.buildPlaneIndexData());

  let (mat2, state) = PhongMaterial.create(state);
  let state =
    state
    // |> PhongMaterial.setAmbient(mat2, (0.1, 0.1, 0.1))
    |> PhongMaterial.setDiffuse(mat2, (0.0, 1., 0.))
    // |> PhongMaterial.setSpecular(mat2, (0.5, 0.0, 0.5))
    |> PhongMaterial.setShininess(mat2, 72.);
  // |> PhongMaterial.setIllum(mat2, 2)
  // |> PhongMaterial.setDissolve(mat2, 1.);

  let (shader2, state) = Shader.create(state);
  // let state = state |> Shader.setHitGroupIndex(shader2, 1);
  let state = state |> Shader.setHitGroupIndex(shader2, 0);

  let state =
    state
    |> GameObject.addTransform(plane1, tran2)
    |> GameObject.addGeometry(plane1, geo2)
    |> GameObject.addPhongMaterial(plane1, mat2)
    |> GameObject.addShader(plane1, shader2);

  state;
};

let getAllRenderGameObjects = state => {
  GameObject.getAllGeometryGameObjects(state);
};

let _getAccumulatedFrameCount = () => 16;

let init = (device, window, state) => {
  let (cameraBufferData, cameraBufferSize, cameraBuffer) =
    BMFRBuffer.CameraBuffer.buildData(device, state);
  let (pixelBufferSize, pixelBuffer) =
    ManageBuffer.StorageBuffer.buildPixelBufferData(window, device);
  let (historyPixelBufferSize, historyPixelBuffer) =
    ManageBuffer.StorageBuffer.buildPixelBufferData(window, device);
  let (taaBufferData, taaBufferSize, taaBuffer) =
    BMFRBuffer.TAABuffer.buildData(device, state);
  let (commonDataBufferData, commonDataBufferSize, commonDataBuffer) =
    BMFRBuffer.CommonDataBuffer.buildData(device, state);

  state
  |> Pass.setAccumulatedFrameIndex(0)
  |> Pass.setJitterArr(
       TAAJitter.generateHaltonJiters(
         _getAccumulatedFrameCount(),
         //  |> Log.printComplete("_getAccumulatedFrameCount")
         Window.getWidth(window),
         Window.getHeight(window),
       ),
       //  |> Log.printComplete("HaltonJiters")
     )
  |> Pass.setUniformBufferData(
       "cameraBuffer",
       (cameraBufferData, cameraBuffer),
     )
  |> Pass.setUniformBufferData("taaBuffer", (taaBufferData, taaBuffer))
  |> Pass.setUniformBufferData(
       "commonDataBuffer",
       (commonDataBufferData, commonDataBuffer),
     )
  |> Pass.setStorageBufferData(
       "pixelBuffer",
       (pixelBufferSize, pixelBuffer),
     )
  |> Pass.setStorageBufferData(
       "historyPixelBuffer",
       (historyPixelBufferSize, historyPixelBuffer),
     );
};

let _updateRayTracingData = state => {
  state
  |> BMFRBuffer.CommonDataBuffer.update(
       Director.getFrameIndex(state),
       DirectionLight.getLightCount(state),
     );
};

let _updateCameraData = (window, state) => {
  let currentCameraView = state |> CameraView.unsafeGetCurrentCameraView;

  let lastViewJitterdProjectionMatrixOpt =
    Pass.GBufferPass.getLastViewJitterdProjectionMatrix(state);
  //     Matrix4.createIdentityMatrix4()
  //     |> Matrix4.multiply(
  //          CameraView.unsafeGetViewMatrix(currentCameraView, state),
  //          TAAJitter.jitterProjectionMatrix(
  //   CameraView.unsafeGetProjectionMatrix(currentCameraView, state),
  // ),
  //   state,
  //        );

  let currentArcballCameraController =
    state |> ArcballCameraController.unsafeGetCurrentArcballCameraController;
  let state =
    state
    |> CameraView.update(
         (
           (Window.getWidth(window) |> float_of_int)
           /. (Window.getHeight(window) |> float_of_int),
           180.0 *. 2. /. 5.,
           0.1,
           4096.0,
         ),
         (
           ArcballCameraController.getLookFrom(
             currentArcballCameraController,
             state,
           ),
           ArcballCameraController.unsafeGetTarget(
             currentArcballCameraController,
             state,
           ),
           (0., 1., 0.),
         ),
       );

  let viewMatrix = CameraView.unsafeGetViewMatrix(currentCameraView, state);
  let jitterdProjectionMatrix =
    TAAJitter.jitterProjectionMatrix(
      CameraView.unsafeGetProjectionMatrix(currentCameraView, state),
      state,
    );
  let state =
    state
    |> Pass.GBufferPass.setLastViewJitterdProjectionMatrix(
         Matrix4.createIdentityMatrix4()
         |> Matrix4.multiply(jitterdProjectionMatrix, viewMatrix),
       );

  let state =
    state
    |> BMFRBuffer.CameraBuffer.update(
         CameraView.unsafeGetCameraPosition(currentCameraView, state),
         viewMatrix,
         jitterdProjectionMatrix,
         lastViewJitterdProjectionMatrixOpt,
       );

  state;
};

let _updateJitterData = state => {
  let state =
    state
    |> BMFRBuffer.TAABuffer.update(
         Pass.getJitter(
           Pass.getAccumulatedFrameIndex(state),
           //  |> Log.printComplete("getAccumulatedFrameCount")
           state,
         ),
       );

  state
  |> Pass.setAccumulatedFrameIndex(
       (Pass.getAccumulatedFrameIndex(state) |> succ)
       mod _getAccumulatedFrameCount(),
     );
};

let _updateTransformAnim = (time, state) => {
  TransformAnimation.getAllDynamicTransforms(state)
  |> ArrayUtils.reduceOneParam(
       (. state, transform) => {
         let (tx, ty, tz) = Transform.getTranslation(transform, state);
         let (rx, ry, rz) = Transform.getRotation(transform, state);

         let newTx = tx +. 0.3 *. time /. 20.0;
         let newTx = newTx > 10.0 ? 0.0 : newTx;

         state
         |> Transform.setTranslation(transform, (newTx, ty, tz))
         |> Transform.setRotation(transform, (rx, ry +. time /. 20.0, rz));
       },
       state,
     );
};

let _updateTransformData = (time, device, queue, state) => {
  let allRenderGameObjects = getAllRenderGameObjects(state);

  let state =
    allRenderGameObjects
    |> ArrayUtils.reduceOneParam(
         (. state, renderGameObject) => {
           state
           |> Pass.GBufferPass.setLastModelMatrix(
                GameObject.unsafeGetTransform(renderGameObject, state),
                Transform.buildModelMatrix(
                  GameObject.unsafeGetTransform(renderGameObject, state),
                  state,
                ),
              )
         },
         state,
       );

  let state = state |> _updateTransformAnim(time);

  let state =
    state
    |> ManageAccelerationContainer.updateInstanceContainer(device, queue);

  let state = state |> BMFRBuffer.ModelBuffer.update(allRenderGameObjects);

  state;
};

let update = (device, queue, window, state) => {
  state
  |> _updateRayTracingData
  |> _updateCameraData(window)
  |> _updateTransformData(Director.getTime(state), device, queue)
  |> _updateJitterData;
};